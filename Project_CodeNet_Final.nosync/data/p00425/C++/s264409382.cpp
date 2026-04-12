#include<iostream>
using namespace std;

int main(){

int n,input[10000],cont,bon,dice[7];
char bin[10];

while(1){

scanf("%d",&n);

if(n==0){
break;
}

for(int i=0;i<7;i++){
dice[i]=i;
}
for(int i=0;i<n;i++){
scanf("%s",bin);
switch(bin[0]){
case 'N':input[i]=1;break;
case 'E':input[i]=2;break;
case 'W':input[i]=3;break;
case 'S':input[i]=4;break;
case 'R':input[i]=5;break;
case 'L':input[i]=6;break;
}
}

cont=0;

for(int i=0;i<n;i++){
cont+=dice[1];
switch(input[i]){
case 1:
bon = dice[1];
dice[1]=dice[2];
dice[2]=dice[6];
dice[6]=dice[5];
dice[5]=bon;
break;
case 2:
bon = dice[1];
dice[1]=dice[4];
dice[4]=dice[6];
dice[6]=dice[3];
dice[3]=bon;
break;
case 3:
bon = dice[1];
dice[1]=dice[3];
dice[3]=dice[6];
dice[6]=dice[4];
dice[4]=bon;
break;
case 4:
bon = dice[1];
dice[1]=dice[5];
dice[5]=dice[6];
dice[6]=dice[2];
dice[2]=bon;
break;
case 5:
bon = dice[2];
dice[2]=dice[3];
dice[3]=dice[5];
dice[5]=dice[4];
dice[4]=bon;
break;
case 6:
bon = dice[2];
dice[2]=dice[4];
dice[4]=dice[5];
dice[5]=dice[3];
dice[3]=bon;
break;
}
}
cont+=dice[1];
printf("%d\n",cont);
}



}