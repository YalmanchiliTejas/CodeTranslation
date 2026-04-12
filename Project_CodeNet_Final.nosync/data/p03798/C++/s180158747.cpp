#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
using namespace std;
typedef pair<int,int> P;//Pでpair<-,->を表す。
typedef long long LL; 

int rev(int x){return 1-x;}

int main()
{ 
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[n];//矛盾に関するデータ
    for(int i=0;i<n;i++){
        if(s[i]=='o'){a[i]=0;}
        else{a[i]=1;}
    }
    int b[n];//裏返しに関するデータ
    for(int i=0;i<n;i++){b[i]=0;}

    int c[3];
    for(int i=0;i<3;i++){c[i]=0;}
    for(int i=0;i<n;i++){
        if(a[i]==1){c[i%3]++;}
    }
    for(int i=0;i<3;i++){c[i]=c[i]%2;}

    if(n%3==0){//不可能パターンの出力
        if(c[0]==0&&c[1]==0&&c[2]==0){}
        else if(c[0]!=0&&c[1]!=0&&c[2]!=0){
            b[0]++;
            a[0]=rev(a[0]);
            a[1]=rev(a[1]);
            a[n-1]=rev(a[n-1]);
        }
        else{cout<<-1<<endl;return 0;}
    }
    if(n%3==2){
        if(c[0]==0&&c[1]==0&&c[2]==1){
            a[0]=rev(a[0]);a[2]=rev(a[2]);a[n-2]=rev(a[n-2]);
            b[n-1]++;b[0]++;b[1]++;
        }
        if(c[0]==0&&c[1]==1&&c[2]==0){
            a[n-2]=rev(a[n-2]);a[n-1]=rev(a[n-1]);a[0]=rev(a[0]);
            b[n-1]++;
        }
        if(c[0]==0&&c[1]==1&&c[2]==1){
            a[n-1]=rev(a[n-1]);a[2]=rev(a[2]);
            b[0]++;b[1]++;
        }
        if(c[0]==1&&c[1]==0&&c[2]==0){
            a[n-1]=rev(a[n-1]);a[0]=rev(a[0]);a[1]=rev(a[1]);
            b[0]++;
        }
        if(c[0]==1&&c[1]==0&&c[2]==1){
            a[n-2]=rev(a[n-2]);a[n-1]=rev(a[n-1]);a[1]=rev(a[1]);a[2]=rev(a[2]);
            b[n-1]++;b[1]++;
        }
        if(c[0]==1&&c[1]==1&&c[2]==0){
            a[n-2]=rev(a[n-2]);a[1]=rev(a[1]);
            b[n-1]++;b[0]++;
        }
        if(c[0]==1&&c[1]==1&&c[2]==1){
            a[0]=rev(a[0]);a[1]=rev(a[1]);a[2]=rev(a[2]);
            b[1]++;
        }
    }
    if(n%3==1){
        if(c[0]==0&&c[1]==0&&c[2]==1){
            a[n-2]=rev(a[n-2]);a[n-1]=rev(a[n-1]);a[0]=rev(a[0]);
            b[n-1]++;
        }
        if(c[0]==0&&c[1]==1&&c[2]==0){
            a[n-1]=rev(a[n-1]);a[1]=rev(a[1]);a[0]=rev(a[0]);
            b[0]++;
        }
        if(c[0]==0&&c[1]==1&&c[2]==1){
            a[n-2]=rev(a[n-2]);a[1]=rev(a[1]);
            b[n-1]++;b[0]++;
        }
        if(c[0]==1&&c[1]==0&&c[2]==0){
            a[0]=rev(a[0]);a[2]=rev(a[2]);a[n-2]=rev(a[n-2]);
            b[n-1]++;b[0]++;b[1]++;
        }
        if(c[0]==1&&c[1]==0&&c[2]==1){
            a[n-1]=rev(a[n-1]);a[2]=rev(a[2]);
            b[0]++;b[1]++;
        }
        if(c[0]==1&&c[1]==1&&c[2]==0){
            a[n-3]=rev(a[n-3]);a[0]=rev(a[0]);
            b[n-2]++;b[n-1]++;
        }
        if(c[0]==1&&c[1]==1&&c[2]==1){
            a[0]=rev(a[0]);a[1]=rev(a[1]);a[2]=rev(a[2]);
            b[1]++;
        }
    }
    for(int i=0;i<n-3;i++){
        if(a[i]==1){a[i+3]=rev(a[i+3]);b[i+1]++;b[i+2]++;}
    }
    string t;
    for(int i=0;i<n;i++){
        if(b[i]%2==1){t=t+'W';}
        else{t=t+'S';}
    }

    cout<<t<<endl;
    return 0;
}