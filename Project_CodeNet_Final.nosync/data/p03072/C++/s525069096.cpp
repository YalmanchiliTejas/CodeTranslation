#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int m = h[0];
    int c = 1;
    for(int i = 1; i < n; i++){
        if(h[i] >= m){
            c++;
            m = h[i];
        }
    }
    cout << c << endl;
    return 0;
}
