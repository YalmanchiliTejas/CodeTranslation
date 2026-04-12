#include <iostream>
#include <vector>

using namespace std;

long long f(int n, long long x){
    vector <long long> a(51); // 層の厚さ
    vector <long long> p(51); // パテの枚数
    a[0] = 1;
    p[0] = 1;
    for(int i = 0; i < 50; i++){
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }

    if (n == 0) {
        if (x <= 0) {
            return 0;
        }else{
            return 1;
        }
    }else{
        if (x == 1) {
            return 0;
        }else if(x <= 1 + a[n - 1]){
            return f(n-1, x-1);
        }else{
            return p[n - 1] + 1 + f(n-1, x-2-a[n-1]);
        }
        
    }
}

int main(){
    long long n, x;
    cin >> n >> x;

    cout << f(n, x) << endl;

    return 0;
}