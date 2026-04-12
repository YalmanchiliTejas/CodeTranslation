//
//  main.cpp
//  Tenka1PBC2019
//
//  Created by hiroaki on 2019/04/21.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
//    int a,b,c;
//    cin >>a>>b>>c;
//    if (a<c&&c<b) {
//        cout<<"Yes"<<endl;
//    }else if(b<c&&c<a){
//        cout<<"Yes"<<endl;
//    }else{
//        cout<<"No"<<endl;
//    }
    
    int n,k;
    string s;
    cin >>n>>s>>k;
    char c = s[k-1];
    string r;
    for (int i=0; i<n; i++) {
        if (s[i]==c) {
            r.push_back(c);
        }
        else{
            r.push_back('*');
        }
    }
    cout<<r<<endl;
    return 0;
}
