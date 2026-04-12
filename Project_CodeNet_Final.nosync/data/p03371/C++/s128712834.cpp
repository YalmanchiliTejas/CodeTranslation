#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    vector<int> AB;
    for (int i=0; i<=max({X, Y}); ++i){
        AB.push_back(2*C*i + A*max({0, X-i}) + B*max({0, Y-i}));
    }
    cout << *min_element(AB.begin(), AB.end()) << endl;
    return 0;
}