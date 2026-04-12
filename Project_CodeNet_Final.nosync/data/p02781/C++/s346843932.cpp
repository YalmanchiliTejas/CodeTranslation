//
//  second.cpp
//  CoderTest
//
//  Created by yuya on 2019/07/25.
//  Copyright © 2019 yuya. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000


int main()
{
    string N;
    int K;
    cin >> N >> K;
    
    ll ret=0;
    
    //int dig = log10(N); // 桁数-1
    int dig = (int)N.size()-1; // 桁数-1
    
    if(K==1){
        // ret += 9*dig + N/pow(10,dig);
        ret += 9 * dig + (N[0]-'0');
        cout << ret << endl;
        
    } else if(K==2){
        /* for(int i=0;i<dig;i++){
            ret += ( N / (int)pow(10,i) ) % 10;
        } */
        
        int nonzero=0;
        for (int i=1; i <= dig; i++) {
            if (nonzero) {
                ret += 9;
            } else if (N[i]-'0' != 0){
                ret += N[i]-'0';
                nonzero = 1;
            }
        }
        
        int head = N[0]-'0';
        ret += (head-1) * 9 * dig;
        
        int comb = dig*(dig-1)/2;
        ret += comb * 9 * 9;
        
        cout << ret << endl;
        
    } else{
        int comb = dig*(dig-1)*(dig-2)/3/2;
        int comb2 = dig*(dig-1)/2;
        int head = N[0]-'0';
        
        
        ret += comb * 9 * 9 * 9;
        ret += (head-1) * comb2 * 9 * 9;
        
        int fnz=INF,snz=INF; // firstnonzero,second
        for (int i=1; i<=dig; i++) {
            if(N[i]-'0' != 0){
                fnz = i;
                break;
            }
        }
        if(fnz < dig){
            for (int i=fnz+1; i<=dig; i++) {
                if(N[i]-'0' != 0){
                    snz = i;
                    break;
                }
            }
        }
        
        for (int i=1; i <= dig-1; i++) {
            for (int j=i+1; j <= dig; j++) {
                if(i == fnz && j == snz){
                    ret += (N[i]-'0' - 1) * 9;
                    ret += N[j]-'0';
                } else if(i == fnz && j > snz){
                    ret += (N[i]-'0') * 9;
                } else if(i > fnz){
                    ret += 9 * 9;
                }
            }
        }
        
        cout << ret << endl;
        
    }
    
    
    return 0;
}
