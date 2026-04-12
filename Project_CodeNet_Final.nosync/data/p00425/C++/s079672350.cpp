#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int n;
int dice[6]={1,2,3,4,5,6};
int ans=1;



void News(int a,int b){
    int temp=0;
    temp=dice[0];
    dice[0]=dice[b];
    dice[b]=dice[5];
    dice[5]=dice[a];
    dice[a]=temp;
    ans+=dice[0];
}

void rl(int a,int b){
    int temp=0;
    temp=dice[1];
    dice[1]=dice[b];
    dice[b]=dice[4];
    dice[4]=dice[a];
    dice[a]=temp;
    ans+=dice[0];
}

void command(string ss){
    if(ss=="North")News(4,1);
    else if(ss=="East")News(2,3);
    else if(ss=="West")News(3,2);
    else if(ss=="South")News(1,4);
    else if(ss=="Right")rl(3,2);
    else if(ss=="Left")rl(2,3);
}

int main(){
    while(cin>>n){
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            cin>>s;
            command(s);
        }
        cout<<ans<<endl;
        for(int i=0;i<=5;i++){
            dice[i]=i+1;
        }
        ans=1;
    }
}
/*
 1 5 5 6 6 2 2 1 North
 1 3 3 6 6 4 4 1 East
 1 4 4 6 6 3 3 1 West
 1 2 2 6 6 5 5 1 South
 2 4 4 5 5 3 3 2 Right
 2 3 3 5 5 4 4 2 Left
 */
 

