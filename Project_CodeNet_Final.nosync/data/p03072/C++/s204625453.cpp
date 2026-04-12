#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    int n, tmp;
    vector<int> h;
    cin >> n;
    int i;
    
    for(i = 0; i < n; i++){
        cin >> tmp;
        h.push_back(tmp);
    }
    
    int m = h[0];
    int count = 1;
    
    for(i = 1; i < n; i++){
        if(m <= h[i]){
            count++;
        }
        m = max(m, h[i]);
    }
    
    cout << count << endl;
}
