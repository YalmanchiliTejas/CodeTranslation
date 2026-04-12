#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

#define min_3(a, b, c) min(a, min(b, c))
#define max_3(a, b, c) max(a, max(b, c))
typedef long long ll;


int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans, rem;
    if(a + b > c * 2){ //ABを2枚買った方が安い時
        ans = c*2 * min(x, y);
        if(x < y){
            rem = y - x;//Bの残った枚数
            if(b > c * 2){
                ans += rem * c * 2;
            }
            else{
                ans += rem * b;
            }
        }else{
            rem = x - y;//Aの残った枚数
            if(a > c * 2){
                ans += rem * c * 2;
            }
            else{
                ans += rem * a;
            }
        }
    }
    else{
        ans = a * x + b * y;
    }

    cout << ans << endl;
}
