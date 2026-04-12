#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1<<pos); }
int turnon(int pos, int mask) { return mask|(1<<pos); }

main()
{
    int n;
    cin>>n;
    if(n>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
