#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define int long long
signed  main(void)
{

    while(true){
        vector<int> A;
        int n, l, r;
        int con = 0;
        
        cin>>n>>l>>r;

        if(!n && !l && !r) break;

        A.resize(n);
        
        for(int i = 0; i < n; i++){
            cin>>A[i];
        }

        for(int i = l; i <= r; i++){
            bool flag = !(n%2);
            for(int j = 0; j < n; j++){
                if(i%A[j] == 0){
                    if(j%2 == 0) flag = true;
                    else flag = false;
                    break;
                }
            }
            if(flag) con++;
        }

        cout<<con<<endl;
    }
    return 0;
}

