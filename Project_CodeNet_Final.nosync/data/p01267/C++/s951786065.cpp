#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, a, b, c, x;
    while(cin >> n >> a >> b >> c >> x, n+a+b+c+x){
        int count = 0;
        vector<int> ans(n);
        for(int i=0; i < n; i++) cin >> ans[i];
        for(int count = 0; ; count++){
            if(10000 < count){cout << -1 << endl; break;}
            if(x == ans[0]){
                vector<int> t;
                for(int i=1; i < ans.size(); i++) t.push_back(ans[i]);
                ans = t;
            }
            if(ans.size() == 0){cout << count << endl; break;}
            x = (a*x+b)%c;
        }
    }
}