#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,count=0,c=0;
    cin >>a;
    c=a*800;
    while(c>=0){
        c -= 800*15;
        count++;
    }
    cout<<a*800-(200*(count-1))<<endl;
}
