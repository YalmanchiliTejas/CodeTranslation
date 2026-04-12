/*
 * Copyright (c) 2019 ... All rights reserved.
 * ...
 */

 #include <iostream>
 #include <iomanip>
 #include <vector>
 #include <algorithm>
 #include <numeric>
 #include <functional>
 #include <cmath>
 #include <queue>
 #include <stack>

 #define repd(i,a,b) for (int i=(a);i<(b);i++)
 #define rep(i,n) repd(i,0,n)
 typedef long long ll;

 using namespace std;


 int inputValue(){
     int a;
     cin >> a;
     return a;
 };

 void inputArray(int * p, int a){
     rep(i, a){
         cin >> p[i];
     }
 };

 void inputVector(vector<int> * p, int a){
     rep(i, a){
         int input;
         cin >> input;
         p -> push_back(input);
     }
 }

 template <typename T>
 void output(T a, int precision) {
     if(precision > 0){
         cout << setprecision(precision)  << a << "\n";
     }
     else{
         cout << a << "\n";
     }
 }

 int main(int argc, const char * argv[]) {

     // source code
     int N = inputValue();
     string S;
     cin >> S;
     int K = inputValue();

     string target = S.substr(K-1, 1);

     rep(i, N){
         string s = S.substr(i, 1);
         if (s != target){
             S.replace(i, 1, "*");
         }
     }

     cout << S << endl;


     return 0;
 }