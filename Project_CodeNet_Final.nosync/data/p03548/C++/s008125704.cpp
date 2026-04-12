#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define repr(i, n) for(int i = n;i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define MOD 1000000007

typedef long long ll;

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int x,y,z,count = 0;
    cin >> x >> y >> z;

    int a = z;

    while(1){
        a += y + z;
        count++;
        if(a > x) break;
    }

    cout << count - 1 << endl;
    
	return 0;
}