#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
	while(cin>>n,n){
        int p=0;
        vector<int> a;
        a.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        
        for(int i=1;i<n-1;i++){
            p+=a[i];
        }
        cout << p/(n-2) << endl;
    }

	return 0;
}