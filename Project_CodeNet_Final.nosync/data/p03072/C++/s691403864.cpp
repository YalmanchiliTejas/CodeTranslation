//
//  main.cpp
//  ABC124
//
//  Created by hiroaki on 2019/05/07.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <climits> //max & min

#define int long long
#define pb(n) push_back(n)
#define ForI(n) for(int i=0;i<n;i++)
#define ForJ(n) for(int j=0;j<n;j++)
#define ForK(n) for(int k=0;k<n;k++)
#define Pr(n) cout<<n<<endl;
#define INS(v,n) for(int i=0;i<n;i++){cin >>v.at(i);}//vector 代入
#define ELM 100001 //問題によっては1000000001に変更
using namespace std;

//int Move(vector<int> v,int n){
//    int m[ELM] ={0};
//    for(int i=0; i<n; i++){
//        m[v[i]]++;
//    }
//    vector<int> s;
//    for (int i=0; i<n; i++) {
//        if (m[v[i]]!=0) {
//            cout<<m[v[i]]<<endl;
//            s.pb(m[v[i]]);
//        }
//    }
//    int move = *max_element(s.begin(), s.end());
//    return move;
//}
signed  main(){
//    ABC124-a
//    int A,B;
//    cin >> A>>B;
//    int ans = 0;
//    sample(2){
//        if(A>B){
//            ans+=A;
//            A--;
//        }else{
//            ans+=B;
//            B--;
//        }
//    }
//    cout<<ans<<endl;
    
//    ABC124-b
    int ans = 0;
    int N;
    cin >> N;
    vector<int> h(N);
    INS(h, N);
    ForI(N){
        int flag=0;
        ForJ(N){
            if (h[i]<h[j]) {
                flag=1;
            }
            if(j>=i){
                break;
            }
        }
        if(flag==0){
            ans++;
        }
    }
    Pr(ans);
    return 0;
}

