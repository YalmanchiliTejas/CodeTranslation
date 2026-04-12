#include<bits/stdc++.h>
using namespace std;

int A[51];

int main(){
    int n,l,r;
    
    while(true){
        cin >> n >> l >> r;
        if(n == 0){
            break;
        }
        for(int i=1; i<=n; i++){
            cin >> A[i];
        }

        int counter = 0;

        for(int num=l; num<=r; num++){
            bool flag = false;
            for(int i=1; i<=n; i++){
                if(num%A[i] == 0){
                    if(i%2==1){
                        counter++;
                    }
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }

            if(n%2==0){
                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}
