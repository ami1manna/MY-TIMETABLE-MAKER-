#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
//-----------------------------------------
static char s[10][6];
int index=-1,day=1;int maxx=700,maxy=700;


void tools(){
    POINT cursorPosition;
    setfillstyle(1,15);

bar(1230,0,1530,900);
readimagefile("marker.jpeg",1250,0,1530,300);
readimagefile("pie.jpeg",1250,350,1530,600);
readimagefile("arrowright.jpeg",1250,650,1530,900);



    while(1){  //while 1
    GetCursorPos(&cursorPosition);

 if(GetAsyncKeyState(VK_LBUTTON )){ //if 1
        int mx,my;
 mx=cursorPosition.x;
my=cursorPosition.y;
if(mx>=1250&&mx<=1530&&my>=0&&my<=300){ //if 2
    while(1){ //while 2


GetCursorPos(&cursorPosition);

 if(GetAsyncKeyState(VK_LBUTTON )){ //if 3
        int mx,my;
 mx=cursorPosition.x;
my=cursorPosition.y;

bar(mx,my,mx+5,my+5);
 }//if 3

if(GetAsyncKeyState(VK_RIGHT))//right arrow
   break;
}//while 2
break ;}//if 2
 }//if 1

    }//wile emd


}
void addsubject(int x,int y){

if(x==180&&y==80){outtextxy(500,30,"C++");strcpy(s[index],"C++");}
else if(x==530&&y==80){outtextxy(500,30,"DBMS");strcpy(s[index],"DBMS ");}                                                                    //y=80,-------------
else if(x==880&&y==80){outtextxy(500,30,"DTE");strcpy(s[index],"DTE");}                                                                    //y=200-------------
else if(x==1230&&y==80){outtextxy(500,30,"CGR");strcpy(s[index],"CGR");}


//---------------------down subjects
else if(x==180&&y==280){outtextxy(500,30,"DSU");strcpy(s[index],"DSU");}                                                                    //y=80,-------------
else if(x==530&&y==280){outtextxy(500,30,"JAVA");strcpy(s[index],"JAVA");}                                                                    //y=200-------------
else if(x==880&&y==280){outtextxy(500,30,"HTML");strcpy(s[index],"HTML");}
else if(x==1230&&y==280){outtextxy(500,30,"CSS");strcpy(s[index],"CSS");}
}
void displaysubject() //fun to display subjects list
{
    int i=0;
    setfillstyle(1,14);



    bar(200,100,350,200);
    bar(550,100,700,200);
    bar(900,100,1050,200);
    bar(1250,100,1400,200);//----+-+upper part
    bar(200,300,350,400);
    bar(550,300,700,400);
    bar(900,300,1050,400);
    bar(1250,300,1400,400);//====lower part


    settextstyle(4,0,11);


    outtextxy(250,130,"C++");//1
    outtextxy(580,140,"DBMS");//--2
    outtextxy(950,140,"DTE");//---3
    outtextxy(1300,140,"CGR");//-----4

    outtextxy(250,330,"DSU");//5----------
    outtextxy(580,330,"JAVA");//6
    outtextxy(950,330,"HTML");//7
    outtextxy(1300,330,"CSS");//8
}
   int cursormove(){
        int x=180,y=80;    //staring cordinates
         displaysubject();         //calling  displaysubject()

        while(1)
        {

        if(GetAsyncKeyState(VK_RIGHT))//right arrow
            {
                   cleardevice();
              displaysubject();
               x+=350;
         rectangle(x,y,190+x,y+140);

            }

             if(GetAsyncKeyState(VK_DOWN))
            {
                cleardevice();
                displaysubject();
                   y+=200;
                rectangle(x,y,190+x,y+140);//down arrow

            }
             if(GetAsyncKeyState(VK_UP))
            {
                cleardevice();
                displaysubject();
                  y-=200;
                rectangle(x,y,190+x,y+140);//up arrow

            }
             if(GetAsyncKeyState(VK_LEFT))
            {   cleardevice();
              displaysubject();

               x-=350;
                rectangle(x,y,190+x,y+140);//left arrow

            }
       if(GetAsyncKeyState(VK_LBUTTON ))
            {  ++index;
                addsubject( x, y);
            }//left click
      if (GetAsyncKeyState(VK_RBUTTON)){ closegraph();return 0;}// PRESS RIGHt to exit

outtextxy(640,470,"PRESS RIGHT CICK TO EXIT");
outtextxy(640,570,"PRESS LEFT CICK TO SELECT ");
outtextxy(640,670,"USE <-  -> ARROW TO MOVE   ");
                       delay(200);
        }
    }


//----------------------------
void table(int rows){

        int gd = DETECT, gm;
    DWORD screenWidth = GetSystemMetrics (SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);
    initgraph (&gd, &gd, "");
    initwindow (screenWidth, screenHeight-40, "");
    int r=ceil(rows/3.0);
    int y=0;
    char a[10];
    //PUT HEADING
                          setfillstyle(1,10); //date
          bar(0,0+y,150,60+y);   //date
                          setfillstyle(1,11);  //day
            bar(150,0,300,60);//day
                            setfillstyle(1,12); //9.00
              bar(310,0,500,60);//9.00
                           setfillstyle(1,13); //1.00
                  bar(510,0,700,60);//1.00
                             setfillstyle(1,12); //4.00
                      bar(710,0,900,60);//4.00
                             setfillstyle(1,13); //7.00
                        bar(910,0,1115,60);//7.00
                              settextstyle(4,0,3);
                            outtextxy(10,15,"DATES");//date
                              outtextxy(160,15,"DAYS");//day
                               outtextxy(320,15,"9.00");//9.00
                                outtextxy(520,15,"1.00");//1.00
                                    outtextxy(720,15,"4.00");//4.00
                                       outtextxy(920,15,"7.00");//7.00
    for(int i=0;i<r;i++){  // help to print  boxes
sprintf(a,"DAY %d:",day++);
        setfillstyle(1,11);//date
        bar(0,80+y,150,120+y);   //date
        setfillstyle(1,10);  //day
        bar(150,80+y,300,120+y);   outtextxy(160,90+y,a);//day
        setfillstyle(1,11); //9.00
        bar(310,80+y,500,120+y);//9.00
         setfillstyle(1,12); //1.00
        bar(510,80+y,700,120+y);//1.00
         setfillstyle(1,13); //4.00
        bar(710,80+y,900,120+y);//4.00
         setfillstyle(1,6); //border
         bar(910,80+y,1115,120+y);//border
         setfillstyle(1,14); //7.00
        bar(925,80+y,1100,120+y);//7.00

        y+=45;
        delay(200);
    }
}
void drawpie(float h,float e,float m,float t)
{
    int gd = DETECT, gm;
    DWORD screenWidth = GetSystemMetrics (SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);
    initgraph (&gd, &gd, "");
    initwindow (screenWidth, screenHeight-40, "");
 char a1[50],a2[50],a3[50];
    int x=getmaxx()/2              ,                   y=getmaxy()/2;
    float hardper=0.0,mediumper=0.0,easyper=0.0;
    int s_angle=0;
    int e_angle=0;
settextstyle(4,0,5);


//sector part -----------------------------------------------
        setfillstyle(1,7);
        sector(x,y,0,360,320,320);

    hardper=((h/t)*100)*3.6;//calcuating hard percentages
    e_angle=hardper;//sending  angle of hardchp
    setfillstyle(1,12);

    sector(x, y,0, e_angle, 300,300);
    mediumper=((m/t)*100)*3.6;//calcuating medium percentages
    s_angle=e_angle;//start angle of medium
    e_angle=mediumper+e_angle;//end angle of medium
    setfillstyle(1,14);

    sector(x, y,s_angle,e_angle, 300,300);
    easyper=((e/t)*100)*3.6;//calcuating medium percentages
    s_angle=e_angle;//start angle of easy
    e_angle=easyper+e_angle;//end angle of easy sub
    setfillstyle(1,9);
    sector(x, y,s_angle,e_angle, 300,300);
//-------------------------------------------------------
setfillstyle(1,12);
    bar(x+300,100,x+330,130);

     setfillstyle(1,9);
    bar(x+350,200,x+380,230);

       setfillstyle(1,14);//12
    bar(x+320,300,x+350,330);
    easyper/=3.6;
    mediumper/=3.6;
    hardper/=3.6;
        sprintf(a2,"%.0f %%-Easy",easyper);
            sprintf(a3,"%.0f %%-Medium",mediumper);
             sprintf(a1,"%.0f %%-Hard",hardper);
     outtextxy(x+330,100,a1);//ESSSS
     outtextxy(x+380,200,a2);//MDDDD
     outtextxy(x+350,300,a3);//HAAARDDD
}

int main ()
{
    int gd = DETECT, gm;



    DWORD screenWidth = GetSystemMetrics (SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);
      initgraph (&gd, &gd, "");
    initwindow (screenWidth, screenHeight-40, "");


    cursormove();

    for(int i=0;i<=index;i++){
        cout<<s[i]<<endl;

    }

    int select = 0, mx, my, day = 0, date = 0;

//--------------------------------------------------------------------------------------------------------------------------------------------------

    static char  h[10][5], m[10][5], e[10][5],finalarray[100][10];
    int choice = 0, n, totalchp = 0, hh = 0, ee = 0, mm = 0, hardchp =0, easychp = 0, mediumchp =0, eachchp_h[30], eachchp_m[30], eachchp_e[30],ch[10];
    n=index+1;
    //cout << "ENTER NUMBER OF SUBJECT " << endl;
    //cin >> n;

    for (int i = 0; i < n; i++)
    {

        cout << "ENTER NUMBER OF CHP of IN  "<<s[i] << endl;
        cin >> ch[i];
        totalchp += ch[i];
    }


    for (int i = 0; i < n; i++)
    {
        cout << "SUBJECT:" << s[i] << endl;
        cout << "ENTER THE LEVEL 1.DIFFICULTY 2.MODERATE  3.SIMPLE" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:		//adding chp name to array
            strcpy (h[hh], s[i]);
            //add chp numbers of to array
            eachchp_h[hh] = ch[i];
            hardchp += ch[i];

            hh++;
            break;

        case 2:
            //adding  chp name to array
            strcpy (m[mm], s[i]);
            //add chp numbers to array
            eachchp_m[mm] = ch[i];
            mediumchp += ch[i];
            mm++;
            break;

        case 3:		//adding chp name to array
            strcpy (e[ee], s[i]);
            //add chp to array
            eachchp_e[ee] = ch[i];
            easychp += ch[i];

            ee++;
            break;



        }

    }

//------------------------background--------------------
table(totalchp );

//----------------------display chapter in arranging order------------



{

int j=0,k=0,l=0;
for(int z=0;z<totalchp;) {
        strcpy (finalarray[z],h[j]);
if(strlen(h[j])!=0){z++;}
       strcpy (finalarray[z],m[k]);
if(strlen(m[k])!=0){z++;}
        strcpy (finalarray[z],e[l]);
if(strlen(h[l])!=0){z++;}
    eachchp_h[j]--;
    eachchp_m[k]-- ;
    eachchp_e[l]--;

  if( eachchp_h[j]<=0){
        j++;}
     if(eachchp_m[k]<=0){
        k++;}
    if(  eachchp_e[l]<=0){
        l++;}


}//----------------------display chapter in arranging order------------
}
// h m e
//h m e
//m e m
{
int yposition= 90;
int xposition= 350;
int arraycounter=0;

 for(int i=0;i<ceil(totalchp/3.0);i++){

    for(int j=0;j<3;j++){
    outtextxy (xposition, yposition,finalarray[arraycounter] );
     xposition+=200;
     arraycounter++;
    }
    outtextxy(925, yposition,"REVISION");

 yposition += 45;
xposition= 350;
 }
}



 tools();

 drawpie( hardchp, easychp, mediumchp,totalchp );


    getch ();
    closegraph ();

}
