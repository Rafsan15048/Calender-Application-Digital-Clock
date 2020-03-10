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





///A
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>


#define M_PI acos(-1)
#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color

float cx,cy;
float radius=100;

void draw_face(float radius);
void get_time(int &h,int &m,int &s);
void second_needle(int s);
void minute_needle(int m,int s);
void hour_needle(int h,int m,int s);















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
    char Var;
    if(mon >12)
    {
        mon = 1;
        year = year+1;
    }
    else if(mon<1)
    {
        mon = 12;
        year-=1;
    }
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

    printf("\n\n\nPress Enter to continue...... :");
    printf("\n\n\nPress N or P to Next or Prev...... :");

    getchar();

    scanf("%c",&Var);

    if( Var == 'N' || Var == 'n')
        printMonth(mon+1,date.yy,20,5);
    else if(Var == 'P' || Var == 'p')
        printMonth(mon-1,date.yy,20,5);

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
    char Var;

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

    printf("\n\nEnter N for Next ans P for Prev ....................");
    printf("\nPress enter for main Menu ............................\n\n\n\n");
    getchar();

    scanf("%c",&Var);

    if(Var == 'P' || Var == 'p')
    {
           printf("\t\t\t\tYEAR %d\n\n",year-1);
            daycode = determinedaycode(year-1);
            determineleapyear(year-1);
            calendar(year-1, daycode);

    }
    else if(Var == 'n' || Var == 'N')
    {
              printf("\t\t\t\tYEAR %d\n\n",year+1);
        daycode = determinedaycode(year+1);
            determineleapyear(year+1);
            calendar(year+1, daycode);
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











///For Analog Clock

int analog(void)
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    /***********************************/
    cx=getmaxx()/2.0; // cx is center x value.
    cy=getmaxy()/2.0; // cy is center y value.
    /** Now the point (cx,cy) is the center of your screen. **/

    float x,y;
    int hour,minute,second;
    draw_face(radius);
    while(!kbhit())
    {
        get_time(hour,minute,second);
        second_needle(second);
        minute_needle(minute,second);
        hour_needle(hour,minute,second);
        circle(cx,cy,2);
        delay(100);
    }


    getch();
    closegraph();
    menu();
    getchar();
    //return 0;

}
//*************** FUNCTIONS DEFINITIONS *****************//

void draw_face(float radius)
{

    int theta=0; // theta is the angle variable.
    float x,y;
    /** Draw Clock Border. **/
    circle(cx,cy,radius+24);
    circle(cx,cy,radius+23);
    /** Draw GREEN material border. **/
    setcolor(BLUE);    // I like a wooden frame!
    /** Paint the border. **/
    for(int i=0; i<9; i++)
        circle(cx,cy,radius+13+i);
    /** Set the color white. **/
    setcolor(RED);
    /** Draw outer-inner border. **/
    circle(cx,cy,radius+12);
    circle(cx,cy,radius+10);
    /** Draw center dot. **/
    circle(cx,cy,2);
    int i=0;
    /** DRAW NUMERIC POINTS **/
    do
    {
        /** Getting (x,y) for numeric points **/
        x=cx+radius*cos(theta*M_PI/180);
        y=cy+radius*sin(theta*M_PI/180);
        /** Draw Numeric Points **/
        circle(x,y,2);
        /* Draw Dots around each numeric points **/
        circle(x+5,y,0);
        circle(x-5,y,0);
        circle(x,y+5,0);
        circle(x,y-5,0);
        /** Increase angle by 30 degrees, which is the circular distance between each numeric points. **/
        theta+=30;
        /** Increase i by 1. **/
        i++;

    }
    while(i!=12);   //LIMIT NUMERIC POINTS UPTO =12= Numbers.
    i=0;
    /** DRAW DOTS BETWEEN NUMERIC POINTS. **/
    do
    {
        putpixel(cx+radius*cos(i*M_PI/180),cy+radius*sin(i*M_PI/180),DARKGRAY);
        i+=6;
    }
    while(i!=360);

    /** FACE COMPLETELY DRAWN. **/
}
//================
/** Function to get the current time. **/
void get_time(int &h,int &m,int &s)
{
    /*time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = gmtime(&rawtime);
    h=t->tm_hour;
    m=t->tm_min;
    s=t->tm_sec;*/
    time_t curtime;
    struct tm *t;
    curtime = time (NULL);
    t = localtime (&curtime);
    h=t->tm_hour;
    m=t->tm_min;
    s=t->tm_sec;
}
//=================
/** Function to draw Second needle. **/
void second_needle(int s)
{

    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(S_N_C);
    sx=cx+S_N_L*cos((angle+s*6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6)*M_PI/180);
    line(cx,cy,sx,sy);
}
/** Function to draw Minute needle. **/
void minute_needle(int m,int s)
{
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(M_N_C);
    sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    line(cx,cy,sx,sy);
}
/** Function to draw Hour needle. **/
void hour_needle(int h,int m,int s)
{
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(H_N_C);
    sx=cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
}






///Digital Clock
int digital()
{
    int gd=DETECT;
    int gm;
    initwindow(1000,600,"C:\\TC\\BGI");
    time_t rawTime;
    struct tm *currentTime;
    char a[100];
    while(!kbhit())
    {
        rawTime=time(NULL);
        currentTime=localtime(&rawTime);
        strftime(a,100,"%I:%M:%S",currentTime);

        setcolor(4);//3478 10 11
        settextstyle(BOLD_FONT, HORIZ_DIR,10);
        outtextxy(210, 170, a);


        strftime(a, 100, "%p", currentTime);
        setcolor(LIGHTGREEN);
        settextstyle(8, HORIZ_DIR, 6);
        outtextxy(800, 120, a);


        strftime(a, 100, "%a, %d %b, %Y", currentTime);
        setcolor(YELLOW);
        settextstyle(8, HORIZ_DIR, 5);
        outtextxy(280, 380, a);


        //delay(1000);
    }


    getch();
    closegraph();
}









///For Everything
void menu()
{
    char Var;
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
        printf("7. See Analog Clock\n");
        printf("8. See Digital Clock\n");
        printf("9. Exit\n");
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
            break;

        case 3:
            system("color 47");
            printf("\n\n\n                                         Please enter a year : ");
            scanf("%d", &year);
            daycode = determinedaycode(year);
            determineleapyear(year);
            calendar(year, daycode);
            system("color 50");
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
            //system("color C9");
            //system("Analog clock 1.cpp");
            //printf("Under Construction");
            analog();
            printf("\nPress Enter to continue......");
            getchar();
            //getchar();
            break;


        case 8:
            digital();
            printf("\nPress Enter to COntinue: ");
            getchar();
            ///menu();
            break;

        case 9 :
            exit(0);

        }
    }
}

int main()
{

    menu();
    return 0;
}
