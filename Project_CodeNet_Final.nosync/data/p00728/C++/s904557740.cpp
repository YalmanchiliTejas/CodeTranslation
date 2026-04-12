#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    while (cin>>n) {
        if (n==0) {
            break;
        } else {
            std::deque<int> deq;
            for (int i=0;i<n;i++) {
                cin>>a;
                deq.emplace_back(a);
            }
            sort(deq.begin(),deq.end());
            deq.erase(deq.begin(),deq.begin()+1);
            sort(deq.begin(),deq.end(),greater<int>());
            deq.erase(deq.begin(),deq.begin()+1);
            int sum=0;
            for (int j=0;j<deq.size();j++) {
                sum+=deq[j];
            }
            int ave=floor(sum/(n-2));
            cout<<ave<<endl;
        }
    }
}

