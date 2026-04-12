#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    LL result = 0;

    for(int i = 1; i <= n; i++){
        if(k >= i){

        }else{
            int j = i - k;
            int r = n - i + 1;
            result += j;
            if(k == 0) result--;
            int t = r / i;
            result += j * t;
            int s = r - (i * t);
            if(k > s){

            }else{
                result += s - k;
            }
        }
    }
    
    cout << result << endl;

    return 0;
}