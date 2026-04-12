
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include <cmath>
#include<stdio.h>
#include<queue>
#include<stack>
#include<set>
#define int long long
#define MAX 1000000000000000000LL
int inf=100000000000007;
using namespace std;
typedef pair<int,int> P;
string alph="abcdefghijklmnopqrstuvwxyz";
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


signed main(){
    int n;cin>>n;
    deque<int> s;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        if(i%2==0)s.push_front(a);
        else s.push_back(a);
    }
    if(n%2==0)reverse(s.begin(),s.end());
    for(int i=0; i<n; i++){
        cout<<s[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;
    return 0;
}
