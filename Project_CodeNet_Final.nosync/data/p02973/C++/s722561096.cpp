#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    vector<int> v(n);
    vector<int> x(0);
    for (int i = 0; i < n; i++) { cin >> v[i]; }
    for(int i=0;i<n;i++){
        m=lower_bound(x.begin(),x.end(),v[i])-x.begin();
        if(m==0){x.insert(x.begin(),v[i]);}
        else{x[m-1]=v[i];}
    }

    cout<<x.size();
    return 0;

}