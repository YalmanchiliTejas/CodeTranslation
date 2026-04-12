#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define vi vector<int>
using namespace std;
int vis[1000][1000];
long long gn;
long long po(long long a,long long b){
    if(b==0)return 1;
    if(b==1)return a;
    if(b&1) return a*po(a*a,(b-1)/2);
    if(b&1^1)return po(a*a,b/2);
    return 1;
}
int vectoint(std::vector<int>v){
    reverse(v.begin(), v.end());
    long long p=0;
    for(int i=0;i<v.size();i++){
        p+=v[i]*po(2,i);
    }
return p;
}
int dp[100][100];
int print(int x,int y){
    if(x<=1){
            if(y>2 || y<=0)return 0;
            else return 1;
    }
  if(dp[x][y]!=0)return dp[x][y];
    else{

    return dp[x][y]=print(x-1,y)+print(x-1,y-1);
} }
void dele(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return ;
    }
    int x=s.top();
    s.pop();
    dele(s,k-1);
    s.push(x);
    return;
}
void sort0(){

}
void finddup(){
    int arr[]={1,2,3,4,5,4};
    int tor=arr[0];
    int hare=arr[0];
    do{
        tor=arr[tor];
        hare=arr[arr[hare]];
    }
    while(hare!=tor);
    hare=arr[0];
    while(hare!=tor){
        hare=arr[hare];
        tor=arr[tor];
    }
    cout<<hare<<endl;
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int t;
    // stack<int>s;
    // s.push(1);
    // s.push(111);
    // s.push(112);
    // s.push(112312);
    // s.push(12312);
    //  s.push(122);


    // cout<<s.size()<<endl;
    // stack<int>p=s;
    // while(!p.empty()){cout<<p.top()<<" ";p.pop();}
    // cout<<endl;
    // dele(s,(s.size()%2==0)?s.size()/2:(s.size()/2)+1);
    // cout<<s.size()<<endl;
    // while(!s.empty()){cout<<s.top()<<" ";s.pop();}
    //finddup();
    //sort0();
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
return 0;
}