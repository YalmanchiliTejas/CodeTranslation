#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INFTY = 1001001001;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;++i){
        cin >> A[i];
    }

    vector<int> vec(N, -INFTY);

    for(int i=0;i<N;++i){
        *(lower_bound(vec.begin(), vec.end(), A[i]) - 1) = A[i];
    }

    int ans=0;
    for(int i=0;i<N;++i){
        if(vec[i] != -INFTY) ++ans;
    }
    cout << ans << endl;
}
