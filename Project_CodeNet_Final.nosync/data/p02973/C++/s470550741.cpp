#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    multiset<int> s;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a; a = -a;
        auto itr = s.upper_bound(a);
        if(itr != s.end()){
            s.erase(itr);
            
        }
        s.insert(a);
    }
    cout << s.size() << endl;
	return 0;
}