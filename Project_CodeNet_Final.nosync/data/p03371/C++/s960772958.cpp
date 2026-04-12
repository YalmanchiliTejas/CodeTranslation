    #include <bits/stdc++.h>
    #define rep(i,n) for(int i = 0; i < (n); i++)
     
    using namespace std;
    using ll = long long;
    using P = pair<int,int>; // 1 つの証言を表す構造体 // 「人」と「0 or 1」
    using Graph = vector<vector<int>>;
    
    int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    for(int i = 1; i <= 100000; i++){
    	if(i > x && i> y) break;
    	else if (i>x) ans+=min(b,c*2);
    	else if (i>y) ans+=min(a,c*2);
    	else ans+=min(a+b,c*2);
    }
   	cout << ans << endl;
     return 0;
    }
    