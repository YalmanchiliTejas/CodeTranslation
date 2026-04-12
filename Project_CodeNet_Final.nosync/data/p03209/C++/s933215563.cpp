#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority queue
#include<deque>//double_ended queue
using namespace std;
long long s[100];
long long p[100];
long long Burger(int n,long long x){//nを下からx枚
    long long res=0;
    if(x>0){
        if(n==0){res=1;}
        else if(x==s[n]){res=p[n];}
        else if(x==1){res=0;}
        else if(x<=s[n-1]+1){res=Burger(n-1,x-1);}
        else if(x==s[n-1]+2){res=1+Burger(n-1,x-1);}
        else{res=1+p[n-1]+Burger(n-1,x-s[n-1]-2);}
    }
    return res;
}
int main()
{ 
    int n;
    long long x;
    cin>>n>>x;
    s[0]=1;
    p[0]=1;
    for(int i=1;i<n+1;i++){
        s[i]=2*s[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    cout<<Burger(n,x)<<endl;
    return 0;
}