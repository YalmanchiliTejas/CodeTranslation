#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
const int NMAX=100666; //LOL
using namespace std;
const int INF=1000000007;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

char c;
void solve()
{
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        cout<<"vowel";
    else
        cout<<"consonant";

}

int main()
{
    // Tic
    clock_t t=clock();
   
    solve();
    cout<<"\n";
 
    //Toc
    t=clock()-t;
    //printf("It took me %d clicks (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}
