#include <iostream>
#include <set>
using namespace std;
long long int A[100000];
int main(void){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    multiset<long long int> color;
    color.insert(A[N-1]);
    for (int i = N-2; i >= 0; i--) {
        auto c = color.upper_bound(A[i]);
        if (c == color.end()) {
            color.insert(A[i]);
        }
        else {
            color.erase(c);
            color.insert(A[i]);
        }
    }
    
    cout << color.size() << endl;
}