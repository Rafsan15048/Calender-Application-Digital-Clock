#include<stdio.h>
#include<stdlib.h>


///For music play
#include<Windows.h>
#include<MMSystem.h>



///For time and date
#include <time.h>
#define LEN 150




///For Year Print
#define TRUE    1
#define FALSE   0
int days_in_month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};




///For Day Print And Month
struct Date
{
    int dd;
    int mm;
    int yy;
};
struct Date date;


void menu();






int check_leapYear(int year)
{
    if(year % 400 == 0 || (year % 100!=0 && year % 4 ==0))
        return 1;
    return 0;
}

int getNumberOfDays(int month,int year)
{
    switch(month)
    {
    case 1 :
        return(31);
    case 2 :
        if(check_leapYear(year)==1)
            return(29);
        else
            return(28);
    case 3 :
        return(31);
    case 4 :
        return(30);
    case 5 :
        return(31);
    case 6 :
        return(30);
    case 7 :
        return(31);
    case 8 :
        return(31);
    case 9 :
        return(30);
    case 10:
        return(31);
    case 11:
        return(30);
    case 12:
        return(31);
    default:
        return(-1);
    }
}

char *getName(int day)
{
    switch(day)
    {
    case 0 :
        return("Sunday");
    case 1 :
        return("Monday");
    case 2 :
        return("Tuesday");
    case 3 :
        return("Wednesday");
    case 4 :
        return("Thursday");
    case 5 :
        return("Friday");
    case 6 :
        return("Saturday");
    default:
        return("Error in getName() module.Invalid argument passed");
    }
    printf("press any key to get back to main menu...");
    getchar();
    menu();
}

void print_date(int mm, int yy)
{
    printf("\n****************************************************\n");
    printf("******************");

    switch(mm)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    }
    printf(" , %d*******************", yy);


    printf("\n****************************************************\n");
}


int getDayNumber(int day,int mon,int year)
{
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while(year >= 100)
    {
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = (year-1)-t1;
    t1 = (t1*2)+t2;
    t1 = (t1%7);
    res = res + t1;
    res = res%7;
    t2 = 0;
    for(t1 = 1; t1 < mon; t1++)
    {
        t2 += getNumberOfDays(t1,y);
    }
    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;
    if(y > 2000)
        res = res + 1;
    res = res % 7;
    return res;
}

char *getDay(int dd,int mm,int yy)
{
    int day;
    if(!(mm>=1 && mm<=12))
    {
        return("Invalid month value");
        printf("press any key to get back to main menu...");
        getchar();
        menu();
    }
    if(!(dd>=1 && dd<=getNumberOfDays(mm,yy)))
    {
        return("Invalid date");
        printf("press any key to get back to main menu...");
        getchar();
        menu();
    }
    if(yy>=1600)
    {
        day = getDayNumber(dd,mm,yy);
        day = day%7;
        return(getName(day));
    }
    else
    {
        return("Please give year more than 1600");
        printf("press any key to get back to main menu...");
        getchar();
        menu();
    }
}
















///print all day of the month
void printMonth(int mon,int year,int x,int y)
{
    int nod, day, cnt, d = 1, x1 = x, y1 = y;
    int z;
    if(!(mon>=1 && mon<=12))
    {
        printf("INVALID MONTH");
        getchar();
        return;
    }
    if(!(year>=1600))
    {
        printf("INVALID YEAR");
        getchar();
        return;
    }

    print_date(mon,year);

    printf("*Sun\tMon\tTue\tWed\tThu\tFri\tSat*\n");
    printf("****************************************************\n\n");

    nod = getNumberOfDays(mon,year);
    day = getDayNumber(d,mon,year);

    z = day;
    while(z)
    {
        printf("\t");
        z--;
    }
    cnt = day;
    for(z=1; z<=nod; z++)
    {
        cnt++;

        printf("%02d\t",z);
        if(cnt%7==0)
        {
            printf("\n");
        }
    }
}














///All Month of the year
char *months[]=
{
    " ",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};




int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1.0)/ 4.0;
    d2 = (year - 1.0)/ 100.0;
    d3 = (year - 1.0)/ 400.0;
    daycode = (year + d1 - d2 + d3) %7;
    return daycode;
}


int determineleapyear(int year)
{
    if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}

void calendar(int year, int daycode)
{
    int month, day;
    for ( month = 1; month <= 12; month++ )
    {

        printf("\n______________________________________________________________________________________________\n\n");
        printf("********      %s    *********", months[month]);
        printf("\n\n***********************************");
        printf("\n*Sun  Mon  Tue  Wed  Thu  Fri  Sat*" );
        printf("\n***********************************\n");

        for ( day = 1; day <= 1 + daycode * 5; day++ )
        {
            printf(" ");
        }

        for ( day = 1; day <= days_in_month[month]; day++ )
        {
            printf("%2d", day );

            if ( ( day + daycode ) % 7 > 0 )
                printf("   " );
            else
                printf("\n " );
        }
        daycode = ( daycode + days_in_month[month] ) % 7;
    }
}








///See time
void see_time()
{
    ///Current time
    char buf[LEN];
    time_t curtime;
    struct tm *loc_time;

///Getting current time of system
    curtime = time (NULL);

/// Converting current time to local time
    loc_time = localtime (&curtime);

///Displaying date and time in standard format
    printf("                                               %s", asctime (loc_time));

    strftime (buf, LEN, "\n                                               Date: %A, %b %d.\n\n", loc_time);
    printf("************************************************************************************************************************");
    fputs (buf, stdout);
    strftime (buf, LEN, "\n                                                  Time : %I:%M %p.\n\n", loc_time);
///strftime(),returns the time into string
    printf("************************************************************************************************************************");
    fputs (buf, stdout);

///Universal time
    time_t orig_format;
    time(&orig_format);

    printf("************************************************************************************************************************");
    printf ("\n                          Universal Time or Greenwich Mean Time (GMT) : %s\n",asctime(gmtime(&orig_format)));
    printf("************************************************************************************************************************");
    printf("\nPress any key to continue : ");
    getchar();
}




///set time
void set_time()
{
    system("start set_time.exe");

}





///Alarm
//time_t now;
//struct tm *right_now;


///Set alarm

/*int alarm()
{
    int hour , minutes;
    system("color AC");
    printf("Enter Hour : ");
    scanf("%d",&hour);
    printf("\nEnter Minutes : ");
    scanf("%d",&minutes);
    system("cls");
    printf("\n\n\n\nAlarm Time Is %d:%d",hour,minutes);
    //system("color 3F");
    while(1)
    {
        time(&now);
        right_now=localtime(&now);

        if(hour == right_now->tm_hour & minutes == right_now->tm_min)
        {
            //system("color D0");
            printf("\n\n\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");
            printf("\n\n*******************************************************Wake Up********************************************************");

            //printf("\nWake Up");
            PlaySound(TEXT("Linkin Park - Final Masquerade1.wav"),NULL,SND_SYNC);
            break;
        }
        else
        {
            free(right_now);
        }
    }
}

*/






///For Everything
void menu()
{
    int choice;
    int d;
    char ch = 'a';
    int year, daycode, leapyear;
    while(1)
    {
        system("color 9F");
        system("cls");
        printf("                                                 Name : Rafsan Jani \n");
        printf("                                                  ID   : CE-15048 \n\n");
        printf("************************************************************************************************************************");
        printf("                                                Calender Application: \n");
        printf("________________________________________________________________________________________________________________________\n");
        printf("________________________________________________________________________________________________________________________\n\n");
        printf("1. Find Out the Day\n");
        printf("2. Print all the day of month\n");
        printf("3. Print All the Month of the year\n");
        printf("4. See Todays time and date\n");
        printf("5. Set Time Or Stop Watch\n");
        printf("6. Alarm Clock\n");
        printf("7. Reminder\n");
        printf("8. Exit");
        printf("\n________________________________________________________________________________________________________________________\n\n\n");
        printf("                                           ENTER YOUR CHOICE :  ");
        scanf("%d",&choice);

        getchar();
        system("cls");
        switch(choice)
        {
        case 1:
            //system("cls");
            system("color D0");
            printf("\n\n\n                                    Enter date (DD MM YYYY) : ");
            scanf("%d %d %d",&date.dd,&date.mm,&date.yy);
            system("color 70");
            printf("\n________________________________________________________________________________________________________________________\n");
            printf("\n                                           Day is : %s",getDay(date.dd,date.mm,date.yy));
            printf("\n________________________________________________________________________________________________________________________\n");
            printf("\n\n\nPress Enter to continue...... : ");
            getchar();
            getchar();
            break;

        case 2 :
            system("color E0");
            printf("\n\n\n                                  Enter month and year (MM YYYY) : ");
            scanf("%d %d",&date.mm,&date.yy);
            system("cls");
            system("color 1F");
            printMonth(date.mm,date.yy,20,5);

            printf("\n\n\nPress Enter to continue...... :");
            getchar();
            getchar();
            break;

        case 3:
            system("color 47");
            printf("\n\n\n                                         Please enter a year : ");
            scanf("%d", &year);
            daycode = determinedaycode(year);
            determineleapyear(year);
            calendar(year, daycode);
            system("color C9");
            printf("\n\n\nPress Enter to continue...... :");
            printf("\n");
            getchar();
            getchar();
            break;

        case 4:
            system("color E0");
            see_time();
            break;
        case 5:
            //system("start sound_1.exe");
            set_time();
            getchar();
            break;

        case 6:
            //printf("Enter 24 hour formate!\n");
            //alarm();
            system("Start Alarm.exe");

            //getchar();
            break;


        case 7:
            system("color C9");
            printf("Under Construction");
            printf("\nPress Enter to continue......");
            getchar();
            break;

        case 8 :
            exit(0);

        }
    }
}

int main()
{

    menu();
    return 0;
}

