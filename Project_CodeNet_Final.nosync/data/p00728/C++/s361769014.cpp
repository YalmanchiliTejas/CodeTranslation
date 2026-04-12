#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> sss(20);
    for (int l=0;l<20;l++){

int A;
cin >>A;
 if (A==0){
        break;
    }
int cnt=0;
vector<int> vec(A);
for (int i=0;i<A;i++){
    cin >> vec[i];
    cnt+=vec[i];
}
sort(vec.begin(),vec.end());

cout << ((cnt-(vec[0]+vec[A-1]))/(A-2))<<endl;
   
    }
}
