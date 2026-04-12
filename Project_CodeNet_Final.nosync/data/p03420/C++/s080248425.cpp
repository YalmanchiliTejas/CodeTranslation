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
LL inf=2147483647;const long long ll =9223372036854775807,ninf=1000000000;const double eps = 1e-6; const long long nll =1000000000000000000;
#define sz size()
#define len(X) strlen(X)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ULL unsigned long long
#define de cout<<"test"<<endl;
#define st system("pause");
#define F first
#define S second
class StonesOnATree
{
    public:
int minStones(vector <int> p, vector <int> w)
{

}
};
int main()
{
  LL a,b;
  while(cin>>a>>b){
        if(b==0){
            cout<<a*a<<endl;
            con;
        }
    LL ans=0;
    LL o=0;
    for(LL i=b+1;i<=a;i++){
        ans+=a/i*(max(o,i-b) );
        ans+=max(o,a%i-b+1);
    }
    cout<<ans<<endl;




  }

    return 0;
}
