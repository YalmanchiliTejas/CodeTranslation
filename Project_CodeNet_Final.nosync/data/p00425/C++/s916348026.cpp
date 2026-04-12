#include<iostream>
#include<string>

using namespace std;

int North(void);
int East(void);
int West(void);
int South(void);
int Right(void);
int Left(void);

int top,front,r,l,back,bottom;

int main(void){
  int n,sum;
  string s;
  
  while(1){
    cin >>n;
    if(n==0)break;

    top=1;
    front=2;
    r=3;
    l=4;
    back=5;
    bottom=6;

    sum=top;

    for(int i=0;i<n;i++){
      cin >>s;
      if(s=="North")sum+=North();
      else if(s=="East")sum+=East();
      else if(s=="South")sum+=South();
      else if(s=="West")sum+=West();
      else if(s=="Left")sum+=Left();
      else if(s=="Right")sum+=Right();
    }
    cout << sum << endl;
  }
  return 0;
}

int North(void){
  int t;

  t=top;
  top=front;
  front=bottom;
  bottom=back;
  back=t;

  return top;
}

int East(void){
  int t;

  t=top;
  top=l;
  l=bottom;
  bottom=r;
  r=t;

  return top;
}

int West(void){
  int t;

  t=top;
  top=r;
  r=bottom;
  bottom=l;
  l=t;

  return top;
}

int South(void){
  int t;

  t=top;
  top=back;
  back=bottom;
  bottom=front;
  front=t;

  return top;
}

int Right(void){
  int t;

  t=front;
  front=r;
  r=back;
  back=l;
  l=t;

  return top;
}

int Left(void){
  int t;

  t=front;
  front=l;
  l=back;
  back=r;
  r=t;

  return top;
}