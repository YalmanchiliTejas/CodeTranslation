#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int num, l, r, i, j, ans = 0;
    while(true){
        cin >> num >> l >> r;
        if(num == 0)
            break;
        vector<int> a(num);
        for(i = 0; i < num; i++){
            cin >> a[i];
        }
        for(ans = 0, i = l; i<= r; i++){
            for(j = 0; j < num; j++){
                if(i % a[j] == 0){
                    if(!(j & 1))
                        ans++;
                    break;
                }
            }
            if(j == num && num % 2 == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
