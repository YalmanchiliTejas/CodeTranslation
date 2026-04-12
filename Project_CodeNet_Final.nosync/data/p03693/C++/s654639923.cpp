#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
#include"iomanip"
using namespace std;
typedef long long ll;
int a[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a[0]>>a[1]>>a[2];
    int b=100*a[0]+10*a[1]+a[2];
    if(b%4==0)
        cout<<"YES\n";
    else cout<<"NO\n";
}