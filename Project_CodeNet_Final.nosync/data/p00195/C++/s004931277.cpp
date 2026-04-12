#include "bits/stdc++.h"

using namespace std;

int main()
{
    int a,b;
   while(true){
    cin >> a >>b;
   if(a==0&&b==0){
        return 0;
   }
    int n=0;
    int mx=a+b;
    for(int i=1;i<5;i++){
        cin >>a >>b;
           if(a==0&&b==0){
                return 0;
            }
            if(mx<(a+b)){
                mx=a+b;
                n=i;
            }
    }
    cout <<(char)('A'+n)<<" " <<mx << endl;
   }
}

