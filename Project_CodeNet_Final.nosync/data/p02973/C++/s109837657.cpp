#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> A(N);
    multiset<long long int> ms;
    for(int n=0; n<N; n++) {
        cin >> A[n];
        
        auto itr=ms.lower_bound(A[n]);
        if(itr!=ms.begin()) {
            itr--;
            ms.erase(itr);
        }
        ms.insert(A[n]);
    }
    
    cout << ms.size() << endl;


    return 0;
    
}