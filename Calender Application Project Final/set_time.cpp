
///from Net
#include<iostream>
#include<stdlib.h>
using namespace std ;
class time
{
public:
    time()
    {

        hour=minute=second=0;
    }
    void set()
    {

        cout<<"What's the time?"<<endl;
L1:
        cout<<"hh :";
        cin>>hour;
        if(hour<0||hour>23)
        {
            cout<<"<hh> must be between 0&23"<<endl;
            goto L1;
        }
L2:
        cout<<"mm :";
        cin>>minute;
        if(minute<0||minute>59)
        {
            cout<<"<mm> must be between 0&59"<<endl;
            goto L2;
        }
L3:
        cout<<"ss :";
        cin>>second;
        if(second<0||second>59)
        {
            cout<<"<ss> must be between 0&59"<<endl;
            goto L3;
        }
        ;
    }
    void  print()
    {
        cout<<(hour<10?"0":"")<<hour<<":"<<(minute<10?"0":"")<<minute<<":"<<(second<10?"0":"")<<second<<endl;
        second++;
    }
    void   on()
    {
        for(int k=0; k>=0; k++)
        {
            if(second==60)
            {
                second=0;
                minute++;
            }
            if(minute==60)
            {
                minute=0;
                hour++;
            }
            if(hour==24)
            {
                hour=0;
            }
            print();
            if(h==hour && m==minute && s==second)
                for(int b=0; b<3; b++)
                    cout<<"\a";
            for(int w=0; w<15000; w++)
                for(int r=0; r<25000; r++)
                {}
            system("cls");
        }
    }
    /*void  alarm()
    {
        {
            cout<<"Set the alarm time:"<<endl;
Q1:
            cout<<"hh :";
            cin>>h;
            if(h<0||h>23)
            {
                cout<<"<hh> must be between 0&23"<<endl;
                goto Q1;
            }
Q2:
            cout<<"mm :";
            cin>>m;
            if(m<0||m>59)
            {
                cout<<"<mm> must be between 0&59"<<endl;
                goto Q2;
            }
Q3:
            cout<<"ss :";
            cin>>s;
            if(s<0||s>59)
            {
                cout<<"<ss> must be between 0&59"<<endl;
                goto Q3;
            }
        }
    }*/

private:
    int hour,minute,second;
    int h,m,s;
};




int main()
{
    system("color CB");
    char operation;
    time t;
    for(int i=0; i>=0; i++)
    {
        cout<<"                                         ============================================"<<endl;
        cout<<"                                         ============Select an operation:==========="<<endl;
        cout<<"                                         ============================================"<<endl;
        cout<<endl<<endl<<endl;
        //cout<<"S(et), P(rint), O(n), A(larm), E(xit)?";
        cout<<"                                           1.Press S(set time )"<<endl;
        cout<<"                                           2.Press P(print set time )"<<endl;
        cout<<"                                           3.Press O(n the clock)"<<endl;
        cout<<"                                           4.Press E(xit)?"<<endl;
        cin>>operation;
        if(operation=='S'||operation=='s')
            t.set();
        if(operation=='P'||operation=='p')
            t.print();
        if(operation=='O'||operation=='o')
            t.on();

        if(operation=='E'||operation=='e')
            exit(0);
    }

    return 0 ;
}

