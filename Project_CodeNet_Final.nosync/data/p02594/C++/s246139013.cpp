#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
#define trace(x) cerr << #x << " = " << x << endl
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("ouput.txt","w",stdout);
    #endif 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
         int x;
	 cin>>x;
	 if(x>=30)
		 cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
    }
    return 0;
} 
