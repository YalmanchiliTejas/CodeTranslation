    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    int main() {
    int n,t,e;
    cin >> n >> t >> e;
    vector<int> c(n);
    for (int i=0; i<n; i++) {
    cin >> c[i];
    }
    for (int i=0; i<n; i++) {
    int a = t / c[i];
    if (a*c[i] >= t-e || (a+1)*c[i] <= t+e) {
    cout << i+1 << endl;
    return 0;
    }
    }
    cout << "-1" << endl;
    return 0;
    }