#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i< (b); i++)
#define REP(i,n) FOR(i,0,n)
#define endl '\n'
#define ll long long
using namespace std;
deque <int> q;
int flag = 0;
int main(){
    int n;
    cin>>n;
    REP(i,n){
        int x;
        cin>>x;
        if(flag)
            q.push_front(x);
        else
            q.push_back(x);
        flag++;
        flag%=2;
    }
    if(flag==0)
    for(auto it:q)
        cout<<it<<" ";
    else
    for(auto it = q.rbegin();it!=q.rend();it++){
        cout<<*it<<" ";
    }
    return 0;
}
