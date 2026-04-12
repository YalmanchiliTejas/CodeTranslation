#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    while(true){
        int N;
        cin >> N;
        if(N==0) break;
        vector<int> a;
        for(int i=0;i<N;i++){
            int b;
            cin >> b;
            a.push_back(b);
        }
        sort(a.begin(),a.end());
        int total=0;
        for(int i=1;i<N-1;i++){
            total+=a[i];
        }
        cout << total/(a.size()-2) << endl;
    }
    return 0;
}