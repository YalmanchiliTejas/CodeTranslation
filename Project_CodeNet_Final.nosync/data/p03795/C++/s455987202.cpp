    // RAM RAM
    #include <bits/stdc++.h>
    #define int long long
    #define pb push_back
    #define ppb pop_back
    #define vi vector<int>
    #define mp make_pair
    #define arrayin(a,n) for(int i=0;i<n;i++){cin>>a[i];}
    #define N 55
    const int MOD=1000000007;
    using namespace std;
     
    int32_t main()
    {
    	ios_base::sync_with_stdio(false);cin.tie(0);
        int n;cin>>n;
        cout<<(15*800-200)*(n/15) + (n%15)*800<<endl;
    	return 0;
    }