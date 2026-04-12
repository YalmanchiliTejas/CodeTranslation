#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb emplace_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


const ll modo=1e9+7;
const ll inf=1e16;
const ll ms=(1e6) +5;



int main()
{
    idfc;

    int a=0;
    int b=0;
    for(int i=0;i<3;i++)
    {
        char e;
        cin>>e;
        if(e=='A')a++;
        else b++;
    }
    if(a&&b)cout<<"Yes";
    else cout<<"No";

    return 0;
}