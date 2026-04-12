    #include <bits/stdc++.h>
    using namespace std;
    
    int main(){
        int n;
        cin >> n;
        long ans = 0;
        long x , y;
        x = n * 800;
        y = n / 15;
        y *= 200;
        cout << x - y << endl;
        return 0;
    }