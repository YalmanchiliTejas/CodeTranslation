#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main() {
    int N;
    int t;
    cin >> N;
    vector <int> m;
    int max1 = -1;
    for(int i = 0; i < N; i++){
        cin >> t;
        m.push_back(t);
    }
    int total = 1;
    max1 = m[0];
    for(int i = 1; i < N; i++){
        if(m[i] >= max1)
            total++;
        if(m[i] > max1)
            max1 = m[i];
    }
    cout << total;
    return 0;
}
