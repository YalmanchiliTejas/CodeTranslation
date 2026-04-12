#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    ll ans = 0;

    {
        ll left = a.back(), right = a.back();
        ll tmp = 0;
        ll li = 0, ri = a.size() - 1;
        while(li < ri){
            if(li + 2 <= ri){
                tmp += abs(left - a.at(li)) + abs(right - a.at(li + 1));
                left = a.at(li);
                right = a.at(li + 1);
                li += 2;
            }else if(li + 1 <= ri){
                tmp += max(abs(left - a.at(li)), abs(right - a.at(li)));
                li += 1;
                break;
            }
            if(li + 2 <= ri){
                tmp += abs(left - a.at(ri - 1)) + abs(right - a.at(ri - 2));
                left = a.at(ri - 1);
                right = a.at(ri - 2);
                ri -= 2;
            }else if(li + 1 <= ri){
                tmp += max(abs(left - a.at(ri - 1)), abs(right - a.at(ri - 1)));
                ri -= 1;
                break;
            }
        }
        ans = max(ans, tmp);
    }

    {
        ll left = a.front(), right = a.front();
        ll tmp = 0;
        ll li = 1, ri = a.size();
        while(li < ri){
            if(li + 2 <= ri){
                tmp += abs(left - a.at(ri - 1)) + abs(right - a.at(ri - 2));
                left = a.at(ri - 1);
                right = a.at(ri - 2);
                ri -= 2;
            }else if(li + 1 <= ri){
                tmp += max(abs(left - a.at(ri - 1)), abs(right - a.at(ri - 1)));
                ri -= 1;
                break;
            }
            if(li + 2 <= ri){
                tmp += abs(left - a.at(li)) + abs(right - a.at(li + 1));
                left = a.at(li);
                right = a.at(li + 1);
                li += 2;
            }else if(li + 1 <= ri){
                tmp += max(abs(left - a.at(li)), abs(right - a.at(li)));
                li += 1;
                break;
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
