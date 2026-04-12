#include<bits/stdc++.h>
using namespace std;
 
int main(){
        int n;
        vector<int> a;
         
        cin >> n;
        int maxim = 0, input;
        for(int i = 0;i < n;++i){
                cin >> input;
                a.push_back(input);
                maxim = max(maxim, input);
        }
         
        vector<int> li;
        for(int i = 1;i <= maxim;++i){
                if(maxim % i == 0){
                        li.push_back(i);
                }
        }
         
        int ans = 0;
        for(int i = 0;i < n;i++){
                int ba = lower_bound(li.begin(), li.end(), a[i]) - li.begin();
                ans += li[ba]-a[i];
        }
         
        cout << ans << endl;
        return 0;
}

