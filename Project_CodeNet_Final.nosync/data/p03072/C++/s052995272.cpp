#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    
    vector<int> hotels(N,0);
    for(int i = 0; i < N; i++) {
        cin >> hotels[i];
    }
    
    int oceanView = 0;
    int leftMax = 0;
    for(auto v : hotels) {
        if(leftMax <= v) {
            oceanView++;
        }
        leftMax = max(leftMax, v);
    }
    cout << oceanView << endl;

    return 0;
}
