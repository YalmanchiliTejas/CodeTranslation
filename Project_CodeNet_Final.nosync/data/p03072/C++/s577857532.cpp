#include <bits/stdc++.h>
using namespace std;
int main()
{
 int N;
 cin >> N;
 vector<int> a(N);
 for(int i=0;i<N;i++){
     cin >> a.at(i);
 }
 int count,max;
 count =1;
 max = a.at(0);
 for(int j=1;j<N;j++){
     if(a.at(j)>=max){
         count++;
         max = a.at(j);
     }
 }
 cout << count <<endl;
}