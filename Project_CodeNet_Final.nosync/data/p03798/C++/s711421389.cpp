//
//  main.cpp
//  AtCoder-B055-D
//
//  Created by Yuuki Tanaami on 2017/02/19.
//  Copyright © 2017年 Yuuki Tanaami. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    string s;
    
    cin >> n >> s;
    int ans[n+1];
    
    //0:羊, 1:狼
    int start=-1,end=-1;
    bool bin=false;
    for (int i=0; i<=1; i++) {
        if(bin==true){
            break;
        }
        if(i==0){
            ans[0] = 0;
            start = 0;
        }else{
            ans[0] = 1;
            start = 1;
        }
        for (int j=0; j<=1; j++) {
            if(bin==true){
                break;
            }
            if(ans[0]==0){
                if(s[0]=='o'){
                    if(j==0){
                        ans[1] = 0;
                        end = 0;
                    }else{
                        ans[1] = 1;
                        end = 1;
                    }
                }else{
                    if(j==0){
                        ans[1] = 0;
                        end = 1;
                    }else{
                        ans[1] = 1;
                        end = 0;
                    }
                }
            }else{
                if(s[0]=='o'){
                    if(j==0){
                        ans[1] = 0;
                        end = 1;
                    }else{
                        ans[1] = 1;
                        end = 0;
                    }
                }else{
                    if(j==0){
                        ans[1] = 0;
                        end = 0;
                    }else{
                        ans[1] = 1;
                        end = 1;
                    }
                }
            }
            for (int k=1; k<n; k++) {
                if(ans[k]==0){
                    if(s[k]=='o'){
                        if(ans[k-1]==0){
                            ans[k+1] = 0;
                        }else{
                            ans[k+1] = 1;
                        }
                        
                    }else{
                        if(ans[k-1]==0){
                            ans[k+1] = 1;
                        }else{
                            ans[k+1] = 0;
                        }
                    }
                }else{
                    if(s[k]=='o'){
                        if(ans[k-1]==0){
                            ans[k+1] = 1;
                        }else{
                            ans[k+1] = 0;
                        }
                        
                    }else{
                        if(ans[k-1]==0){
                            ans[k+1] = 0;
                        }else{
                            ans[k+1] = 1;
                        }
                    }
                }
                if(k==n-2){
                    if(end!=ans[n-1]){
                        break;
                    }
                }else if(k==n-1){
                    if(start==ans[n]){
                        bin = true;
                        break;
                    }
                }
            }
        }
    }
    if(bin==true){
        for (int i=0; i<n; i++) {
            if(ans[i]==0){
                cout << 'S';
            }else{
                cout << 'W';
            }
        }
        cout << endl;
    }else{
        cout << "-1" << endl;
    }
    

    return 0;
}
