#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

vector<lint> ALL(51);
vector<lint> P(51);

lint solve(lint n,lint x){
    if(x==0)return 0;
    if(n==0)return 1;
    if(x==1)return 0;
    if(ALL[n]==x)return P[n];
    if(x<=ALL[n-1]+1)return solve(n-1,x-1);
    if(x==ALL[n-1]+2)return solve(n-1,x-2)+1;
    return solve(n-1,ALL[n-1])+1+solve(n-1,x-ALL[n-1]-2);
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    P[0]=1;
    ALL[0]=1;
    for(int i=1;i<=50;i++){
        ALL[i]=ALL[i-1]*2+3;
        P[i]=P[i-1]*2+1;
    }
    lint n,x;cin>>n>>x;
    cout<<solve(n,x)<<endl;
}
