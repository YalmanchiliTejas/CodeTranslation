#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define ll long long
//#define __int64 long long

int n;
ll a[233333];


int main(void){
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)a[i]*=-1;
    
    multiset<ll>ta;
    rep(i,n){
        auto itr=ta.upper_bound(a[i]);
        if(itr==ta.end()){
            ta.insert(a[i]);
            //cout<<"A"<<a[i]<<endl;
        }
        else{
            //cout<<"B"<<a[i]<<" "<<(*itr)<<endl;
            ta.erase(itr);
            ta.insert(a[i]);
        }
    }
    cout<<ta.size()<<endl;
}
