#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 10000000000000007
#define eps 1e-8
#define PI 3.14159265359
#define sp printf(" ")
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pcc pair<char, char>
#define mp make_pair
#define FF first
#define SS second
#define pb(x) push_back(x)
#define sd(x) scanf("%d", &(x))
#define pd(x) printf("%d", (x))
#define pdn(x) printf("%d\n", (x))
#define sld(x) scanf("%ld", &(x))
#define pld(x) printf("%ld", (x))
#define pldn(x) printf("%ld\n", (x))
#define slf(x) scanf("%lf", &(x))
#define plf(x) printf("%.9lf", (x))
#define plfn(x) printf("%.12lf\n", (x))
#define sch(x) scanf("%c", &(x))
#define pch(x) printf("%c", (x))
#define pchn(x) printf("%c\n", (x))
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define ios ios::sync_with_stdio(false); cin.tie(0) ; cout.tie(0)
#define endl '\n'
using namespace std;
int a[200004],b[210004];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=100041;int r=l+1;
    b[l]=a[1];
    l--;
    if(n==1){cout<<a[1]<<endl;return 0;}
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            b[r]=a[i];
            r++;
            if(i==n)
            {
                                for(int i=r-1;i>l;i--)cout<<b[i]<<" ";
                cout<<endl;

            }
        }
        else
        {
            b[l]=a[i];
            l--;
            if(i==n)
            {
                                for(int i=l+1;i<r;i++)cout<<b[i]<<" ";
                cout<<endl;

            }

        }

    }






}


