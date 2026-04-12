#include <bits/stdc++.h>

using namespace std;


int main(){
    
    int n,l,r;
    while(cin >> n >> l >> r){
        if(n == 0 && l == 0 && r == 0)
            return 0;
        vector<int> vec;
        for(int i = 0;i < n;i++){
            int b;cin >> b;
            vec.push_back(b);
        }
        int ans = 0;
        for(int i = l;i <= r;i++){
            bool f = true;
            bool e = false;
            for(int j = 0;j < n;j++){
                if(i % vec.at(j) == 0){
                    f = false;
                    if((j + 1) % 2){
                        e = true;
                    }
                    break;
                }
            }
            
            if(f && n%2 == 0){
                e = true;
            }
            
            if(e){
                ans++;
               // cout << i << endl;
            }
        }
       
        //cout<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}
