 #include <bits/stdc++.h> 
 using namespace std; 
 int main() { 
   int i ;
   string S;
   for(int i=0;i<3;i++) {
   cin>> S[i];
   }
   string Ans="Yes";
   
   if(S[0]=='A' && S[1]=='A' && S[2]=='A') Ans="No";
   if(S[0]=='B' && S[1]=='B' && S[2]=='B') Ans="No";
   
   cout<<Ans<<endl;
   return 0; 
 }
