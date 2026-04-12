#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
    long long ans = 0;
	cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool f = true;
    while(f){
        f = false;
        for(int i = 0; i < n; i++){
            if(a[i] < n) continue;
            long long t = a[i] / n;
            a[i] %= n;
            ans += t;
            f = true;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                a[j] += t;
            }
        }
    }
	cout << ans << endl;
	return 0;
}
