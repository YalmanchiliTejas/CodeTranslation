#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
typedef long long int ll;
using namespace std;
bool G[10][10]={false};

int main(){
cin.tie(0);
ios::sync_with_stdio(false);

int N,M;
cin>>N>>M;
rep(i,M){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a][b]=G[b][a]=true;
}

vector<int> ord(N);
rep(i,N)ord[i]=i;
int res=0;
do{
    if(ord[0]!=0) break;

    bool ok=true;
    rep(i,N-1){
        int from=ord[i];
        int to=ord[i+1];
        if(!G[from][to]) ok = false;
    }
    if(ok) res++;
}while(next_permutation(ord.begin(),ord.end()));
cout<<res<<endl;
//system("pause");
return 0;
}