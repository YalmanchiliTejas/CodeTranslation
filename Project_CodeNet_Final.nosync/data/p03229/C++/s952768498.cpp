#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin>>N;

    vector<int> A;
    vector<int> cof1;
    vector<int> cof2;
    long long int diff1=0;
    long long int diff2=0;

    A.resize(N);
    cof1.resize(N);
    cof2.resize(N);

    for(int i=0; i<N; ++i)
        cin>>A[i];

    sort(A.begin(), A.end());

    cof1[0] = -1;
    if(N%2==0)
        cof1[N-1] = 1;
    else
        cof1[N-1] = -1;

    for(int i=1; i<N-1; ++i)
    {
        if(i%2==0)
            cof1[i] = -2;
        else
            cof1[i] = 2;
    }

    std::sort(cof1.begin(), cof1.end());
    for(int i=0; i<N; ++i)
        diff1 += cof1[i] * A[i];

    cof2[0] = 1;
    if(N%2==0)
        cof2[N-1] = -1;
    else
        cof2[N-1] = 1;

    for(int i=1; i<N-1; ++i)
    {
        if(i%2==0)
            cof2[i] = 2;
        else
            cof2[i] = -2;
    }

    std::sort(cof2.begin(), cof2.end());
    for(int i=0; i<N; ++i)
        diff2 += cof2[i] * A[i];

    cout<<max(diff1, diff2)<<endl;

    return 0;
}