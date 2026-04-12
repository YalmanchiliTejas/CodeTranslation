#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    /*LIS*/
    multiset<int> s;
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(a[i]);
        if(it == s.begin()){
            s.insert(a[i]);
        }else{
            s.erase(--it);
            s.insert(a[i]);
        } 
    }
    cout << s.size() << endl;
    return 0;
}
