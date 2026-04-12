#include<bits/stdc++.h>
using namespace std;


#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define w(x)  int x; cin>>x; while(x--)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

#define ll  long long
#define all(c) (c).begin(),(c).end()
#define endl "\n"

typedef vector<int> vl;
typedef vector< vl > vvl;
typedef pair< int, int> pll;
typedef map< int, int> mll;
void c_p_c()
{
#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void parray(int a[],int n){
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int i,n,k;
    c_p_c();

    // cout<<"aa"<<endl;
    cin>>n;
    if(n<30)
    	cout<<"No"<<endl;
    else
    	cout<<"Yes"<<endl;
    return 0;
}
