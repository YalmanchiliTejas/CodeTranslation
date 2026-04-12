#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<int> a;
    while(cin>>n){
        if(n==0)break;
        a.clear();
        for(int i = 0; n > i; i++){
            int tmp;cin>>tmp;
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        int sm = 0;
        for(int i = 1; a.size()-1 > i; i++){
            sm += a[i];
        }
        cout << sm/(n-2) << endl;
    }
}
