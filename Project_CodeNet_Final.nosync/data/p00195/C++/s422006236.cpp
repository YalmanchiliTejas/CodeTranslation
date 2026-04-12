#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sum[5];
int sum2[5];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    while(cin >> a >> b && (a || b)){
        sum[0] = a + b;
        sum2[0] = sum[0];
        for(int i = 1; i < 5; ++i){
            int s1, s2;
            cin >> s1 >> s2;
            sum[i] = s1 + s2;
            sum2[i] = sum[i];
        }

        sort(sum, sum + 5);

        for(int i = 0; i < 5; ++i){
            if(sum2[i] == sum[4]){
                cout << char('A' + i) << " " << sum[4] << endl;
            }
        }
    }

    return 0;
}