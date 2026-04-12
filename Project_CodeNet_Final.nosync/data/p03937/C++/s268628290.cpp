#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>
#include <map>

typedef long long ll;
#define rep(i, a, n) for(int i = a; i<n; i++)
#define ALL(a) begin(a), end(a)
#define mii map<int, int>
#define msi map<string, int>
#define vi vector<int>
#define vl vector<ll>
#define MOD 1000000007
#define INF 1e9
#define showVector(v) rep(i,0,v.size()){p(v[i]);p(" ")} pl("")
#define p(s) std::cout << s ;
#define pl(s)  std::cout << s << endl;
using namespace std;

// 素数判定 O(√n)
bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;

}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, 0, H) {
        cin >> a[i];
    }
    int y = 0;
    int x = 0;
    while(true) {
        if (y+1==H&&x+1==W) {
            if (a[y-1][x] == '#' && a[y][x-1] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
            cout << "Possible" << endl;
            return 0;
        }

       if (y+1<H && x+1<W) {
            if (y >= 0 && x >= 0) {
                if (a[y+1][x] == '#' && a[y][x+1] == '#') {
                    cout << "Impossible" << endl;
                    return 0;
                }
                if (a[y+1][x] == '.' && a[y][x+1] == '.') {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }

            if (y > 0 && x > 0) {
                if (a[y-1][x] == '#' && a[y][x+1] == '#' && a[y][x-1] == '#') {
                    cout << "Impossible" << endl;
                    return 0;
                }

                if (a[y-1][x] == '#' && a[y+1][x] == '#' && a[y][x-1] == '#') {
                    cout << "Impossible" << endl;
                    return 0;
                }

                if (a[y][x-1] == '#' && a[y][x+1] == '#' && a[y-1][x] == '#') {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }

        if (y+1<H && x+1<W) {
                if (a[y+1][x] == '#' && a[y][x+1] != '#') {
                    y++;
                    continue;
                }

                if (a[y][x+1] == '#' && a[y+1][x] != '#') {
                    x++;
                    continue;
                }
        }
        if (y+1==H || x+1==W) {
             if (x+1==W&&y+1<H) {
                if (a[y+1][x] == '#') {
                    if (y > 0 && x > 0) {
                        if (a[y-1][x] == '#' && a[y][x-1] == '#') {
                            cout << "Impossible" << endl;
                            return 0;
                        }
                    }
                    y++;
                    continue;
                } else {
                    cout << "Impossible" << endl;
                    return 0;
                }
             }

             if (y+1==H&&x+1<W) {
                if (a[y][x+1] == '#') {
                    if (y > 0 && x > 0 ) {
                        if (a[y][x-1] == '#' && a[y-1][x] == '#') {
                            cout << "Impossible" << endl;
                            return 0;
                        }
                    }
                    x++;
                    continue;
                } else {
                    cout << "Impossible" << endl;
                    return 0;
                }
             }
        }

 
    }
    return 0;
}
