#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define MOD 1000000007

int gcd(int a, int b){
    if( a < b){
        swap(a,b);
    }
    return (a % b == 0)? b:gcd(a, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

ll combination(int parent, int choice){
    if( choice == 0 ){
        return 1;
    }

    ll ans = 1;

    repn(i,1,choice+1){
        ans *= parent + 1 - i;
        ans /= i;
    }

    return ans;
} 

bool check(string target, int num){
    rep(i,target.length()){
        if( num == 0 ) return true;
        if( target.at(i) - '0' > 0 ){
            num--;
        }
    }
    return (num == 0);
}

long long solve(string target, int depth){
    ll ans = ( check(target, depth + 1) )? 1 : 0;

    int length = target.length();
    rep(i,length){
        if( depth < 0 ) break;
        int target_decimal = target.at(i) - '0';
        if( target_decimal > 0 ){
            target_decimal--;
            ans += target_decimal * combination(length - i - 1, depth) * pow(9, depth);
            repn(j,i+1,length){
                ans += 9 * combination(length - j - 1, depth) * pow(9, depth);
            }
            depth--;
        }
    }

    return ans;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << solve(s, k-1) << endl;

}