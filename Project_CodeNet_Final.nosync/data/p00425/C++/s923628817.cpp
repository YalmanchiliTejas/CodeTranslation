#include <iostream>
using namespace std;

void North(int *t, int *b, int *n, int *e, int *s, int *w);
void East(int *t, int *b, int *n, int *e, int *s, int *w);
void South(int *t, int *b, int *n, int *e, int *s, int *w);
void West(int *t, int *b, int *n, int *e, int *s, int *w);
void Right(int *t, int *b, int *n, int *e, int *s, int *w);
void Left(int *t, int *b, int *n, int *e, int *s, int *w);

int main(void){
    int n, top, bottum, north, east, south, west, sum;
    string Turn;
    
    while(1){
        cin >> n;
        if(n==0) break;
        top=1; bottum=6; north=5; east=3; south=2; west=4; //初期化
        sum=top;
        for(int i=0; i<n; i++){
            cin >> Turn;
            if(Turn=="North"){
                North(&top, &bottum, &north, &east, &south, &west);
            }
            else if(Turn=="East"){
                East(&top, &bottum, &north, &east, &south, &west);
            }
            else if(Turn=="South"){
                South(&top, &bottum, &north, &east, &south, &west);
            }
            else if(Turn=="West"){
                West(&top, &bottum, &north, &east, &south, &west);
            }
            else if(Turn=="Right"){
                Right(&top, &bottum, &north, &east, &south, &west);
            }
            else if(Turn=="Left"){
                Left(&top, &bottum, &north, &east, &south, &west);
            }
            //cout << top << bottum << north << east << south << west << endl;
            sum += top;
        }
        cout << sum << endl;
    }
    return 0;
}
void North(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*t;
    *t=*s;
    *s=*b;
    *b=*n;
    *n=temp;
}
void East(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*t;
    *t=*w;
    *w=*b;
    *b=*e;
    *e=temp;
}
void South(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*t;
    *t=*n;
    *n=*b;
    *b=*s;
    *s=temp;
}
void West(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*t;
    *t=*e;
    *e=*b;
    *b=*w;
    *w=temp;
}
void Right(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*s;
    *s=*e;
    *e=*n;
    *n=*w;
    *w=temp;
}
void Left(int *t, int *b, int *n, int *e, int *s, int *w){
    int temp;
    temp=*s;
    *s=*w;
    *w=*n;
    *n=*e;
    *e=temp;
}

