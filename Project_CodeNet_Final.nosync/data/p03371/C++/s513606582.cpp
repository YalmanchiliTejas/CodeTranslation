using namespace std;
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int adda, addb, sum;
    int minp = INT_MAX;
    for (int i = 0; i <= 100000; i++){
        minp = min(i * 2 * c + max(0,x-i) * a + max(0,y-i) * b, minp);
    }

    cout << minp << endl;



}
