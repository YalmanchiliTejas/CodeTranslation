#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl; 

int n,m;
int edge[10][10]={};
vector<int> A;




int main(){
    cin >> n >> m;
    int a,b;
    REP(i,m){
        cin >> a >> b;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    FOR(i,2,n+1){
        A.push_back(i);
    }

    int tmp_v;
    bool flag;
    int ans=0;
    while(1){
        flag = true;
        tmp_v=1;
        itrfor(itr,A){
            if(edge[tmp_v][*itr] == 0){
                flag =false;
                break;
            }
            tmp_v= *itr;
        }
        if(flag) ans += 1;
        if(not next_permutation(A.begin(),A.end())) break;

    }
    print(ans);



}