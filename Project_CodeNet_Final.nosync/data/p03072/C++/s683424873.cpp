#include <bits/stdc++.h>
using namespace std;


#define M_MAX 20
#define N_MAX 50000
#define INFTY 1 << 29

int main(){
int n;
cin >> n;
int h[n];
int maxi=0;
int count=0;
for(int i=0;i<n;i++){
cin >> h[i];
if(maxi<=h[i])count++;
maxi=max(maxi,h[i]);
}
cout << count;

}
