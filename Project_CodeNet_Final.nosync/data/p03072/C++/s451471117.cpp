#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int res = 1;
    int max = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] >= max){
            res++;
            max = v[i];
        }
    }
    cout << res << endl;
    return 0;
}
