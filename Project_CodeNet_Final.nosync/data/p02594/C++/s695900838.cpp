#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}

int main()
{
    IO
	clock_t begin = clock();
    int n;
    cin>>n;
    if(n>=30)
    	cout<<"Yes\n";
    else
    	cout<<"No\n";
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}