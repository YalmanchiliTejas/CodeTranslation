#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    int y = 0, x = 0;
    string s[h];
    for(int i=0;i<h;i++) cin >> s[i];
    map<pair<int,int>, int > mp;
    mp[{h-1, w-1}] = 1;
    while(!(y == h-1 && x == w-1)){
    	mp[{y, x}] = 1;
    	if(y == h-1){
    		if(s[y][x+1] == '#') x++;
    		else{
    			cout << "Impossible" << endl;
    			return 0;
    		}
    	}else if(x == w-1){
    		if(s[y+1][x] == '#') y++;
    		else{
    			cout << "Impossible" << endl;
    			return 0;
    		}
    	}else{
    		if(s[y][x+1] == '#'){
    			if(s[y+1][x] == '#'){
    			    cout << "Impossible" << endl;
    			    return 0;
    			}else{
    				x++;
    			}
    		}else{
    			if(s[y+1][x] == '#') y++;
    			else{
    				cout << "Impossible" << endl;
    			    return 0;
    			}
    		}
    	}
    }
    bool ok = true;
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		if(s[i][j] == '#' && mp[{i, j}] != 1) ok = false; 
    	}
    }
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
