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
LL MOD=1000000007;

int Ctoi(char c){
    return c-'0';
}

LL ans;

LL calc(int k,string t){
    while(!t.empty()&&t[0]=='0'){t=t.substr(1,t.size()-1);}
    int n=t.size();
    if(k==0){return 1;}
    else{
        if(n>=k){
            LL x=calc(k-1,t.substr(1,t.size()-1));
            LL y;
            LL z;
            LL y1,y2,y3;
            y1=(n-1)*9;
            y2=(n-1)*(n-2)*81/2;
            y3=(n-1)*(n-2)*(n-3)*729/6;
            if(k==1){y=y1;z=(Ctoi(t[0])-1)*1;}
            if(k==2){y=y2;z=(Ctoi(t[0])-1)*y1;}
            if(k==3){y=y3;z=(Ctoi(t[0])-1)*y2;}
            return x+y+z;
        }
        else{return 0;}
    }
}

int main()
{ 
    string s;
    cin>>s;
    int k;
    cin>>k;
    LL ans=0;
    ans=calc(k,s);
    cout<<ans<<endl;
    return 0;
}