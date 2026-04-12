#include<iostream>
using namespace std;
int main()
{
    unsigned long long ans = 0;
    int n;
    long long a[51];
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    long long need = sum - n * n;
    while(need > 0){
        long long delta = 0;
        for(int i = 1; i <= n; i++){
            long long need_for = (a[i] + need) / (n + 1);
            if((a[i] + need) % (n + 1) != 0){
                need_for++;
            }
            a[i] -= (n + 1) * need_for;
            delta += need_for;
        }
        for(int i = 1; i <= n; i++){
            a[i] += delta;
        }
        ans += delta;
        need -= delta;
        delta = 0;
    }
    long long border = n - 1;
    while(true){
        bool check = true;
        for(int i = 1; i <= n; i++){
            if(a[i] > border){
                check = false;
                long long need_for = (a[i] - border) / n;
                if((a[i] - border) % n != 0){
                    need_for++;
                }
                ans += need_for;
                a[i] -= (n + 1) * need_for;
                border -= need_for;
            }
        }
        if(check == true){
            break;
        }
    }
    /*cout << "border " << border << endl;
    for(int i = 1; i <= n; i++){
        cout << a[i] << endl;
    }*/
    cout << ans << endl;
    return 0;
}


