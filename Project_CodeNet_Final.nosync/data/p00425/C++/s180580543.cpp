#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
void Direction(void);  //方角の入力 
void North(void);      //北へ回す
void East(void);       //東へ回す 
void West(void);       //西へ回す
void South(void);      //南へ回す
void Right(void);      //右回転
void Left(void);       //左回転

int sum,n;
int ove,cen,rig,lef,bac,und;   //さいころの場所ごとの状態を示す。
char way[10]={'\0'};

using namespace std;

int main(){

  while(1){


  /*さいころの初期状態*/
  ove=1;  //上
  cen=2;  //前
  rig=3;  //右
  lef=4;  //左
  bac=5;  //後
  und=6;  //下
  sum=1;  //合計値

    scanf("%d",&n);

    if(n==0)break;

    Direction();

    printf("%d\n",sum);
  }

  return 0;
}

void Direction(){

  int i;

  for(i=0;i<n;i++){

    scanf("%s",way);

    if(strcmp(way,"North")==0){

      North();

    }

    else if(strcmp(way,"East")==0){

      East();

    }

    else if(strcmp(way,"West")==0){

      West();

    }

    else if(strcmp(way,"South")==0){

      South();
   
    }

    else if(strcmp(way,"Right")==0){

      Right();

    }

    else if(strcmp(way,"Left")==0){

      Left();

    }

  }

}

void North(){

  int temp;

  temp=cen;
  cen=und;
  und=bac;
  bac=ove;
  ove=temp;

  sum+=ove;


}
void East(){

  int temp;

  temp=lef;
  lef=und;
  und=rig;
  rig=ove;
  ove=temp;

  sum+=ove;

}

void West(){

  int temp;

  temp=rig;
  rig=und;
  und=lef;
  lef=ove;
  ove=temp;

  sum+=ove;

}

void South(){

  int temp;

  temp=bac;
  bac=und;
  und=cen;
  cen=ove;
  ove=temp;

  sum+=ove;

}

void Right(){

  int temp;

  temp=cen;
  cen=rig;
  rig=bac;
  bac=lef;
  lef=temp;

  sum+=ove;

}

void Left(){

  int temp;

  temp=cen;
  cen=lef;
  lef=bac;
  bac=rig;
  rig=temp;

  sum+=ove;
  
}