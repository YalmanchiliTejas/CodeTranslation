#include <algorithm>
#include <iostream>
using namespace std;
main() {
    int N; cin>>N;
    int max_=-1, count_=0;
    for(int n=1; n<=N; ++n) {
        int H; cin>>H;
        if(H>=max_) ++count_;
        max_= max(max_, H);
    }
    cout<< count_ <<endl;
}