#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
#define vi vector <int>
using namespace std;
typedef long long ll;
const int N = 1e5+228;
const int big = 2e9;
const int md = 1e9 + 7;
string a;
int k,f[10010][110][2];
void up(int &x,int y){x=(x+y)%md;}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>a;
    cin>>k;
    f[0][0][0]=1;
    FF(i,re(a)){
        FF(s,2){
            FF(sm,k){
                FF(j,10){
                    if (s==0 && j>(a[i]-'0')) continue;
                    up(f[i+1][(sm+j)%k][s|(j<(a[i]-'0'))],f[i][sm][s]);
                }
            }
        }
    }
    cout<<(f[re(a)][0][0]+f[re(a)][0][1]-1+md)%md;
    return 0;
}





