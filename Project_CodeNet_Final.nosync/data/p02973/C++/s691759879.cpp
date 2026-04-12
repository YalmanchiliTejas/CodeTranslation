#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) A[i] = -A[i];

    multiset<int> ms;
    for(int i=0; i<N; i++){
        auto itr = ms.upper_bound(A[i]);
        if(itr == ms.end()) ms.insert(A[i]);
        else{
            ms.erase(itr);
            ms.insert(A[i]);
        }
    }
    cout << ms.size() << endl;
    return 0;
}