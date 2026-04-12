#include<bits/stdc++.h>
using namespace std;
#define con continue
#define bk break
#define LL long long
#define db double
#define pt cout<<'\n'
#define ms(a, b) memset((a), (b), sizeof(a))
#define mp make_pair
#define endl '\n'
int inf=2147483647;const long long ll =9223372036854775807,ninf=1000000000;const double eps = 1e-6; const long long nll =223372036854775807;
#define sz size()
#define len(X) strlen(X)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ULL unsigned long long
#define de cout<<"test"<<endl;
#define st system("pause");
#define M_PI 3.1415926
int A[200005]={};
int vis[200005]={};
int main()
{
    int a;
    while(cin>>a){
        for(int i=0;i<a;i++)
            cin>>A[i];
        for(int i=a-1;i>=0;i-=2){
            cout<<A[i]<<" ";
            vis[i]=1;
        }
        for(int i=0;i<a;i++){
            if(!vis[i])
            cout<<A[i]<<" ";
        }
        pt;
    }

    return 0;
}
