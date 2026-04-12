    #include <bits/stdc++.h>
    #include<algorithm>
    
    using namespace std;

int main() {
   int N,max;
   int count = 1;
   int judge = 0;
   cin >> N;
   vector<int> H(N);
   for(int i=0;i<N;i++){
       cin >> H.at(i);
   }

    for(int i=1;i<N;i++){
       for(int j=0;j<i;j++){
           if(H.at(i)<H.at(j)){
               judge++;
           }
        }
        if(judge == 0)
            count+=1;
        
        else
        {
            judge = 0;
        }
    }  
    cout << count << endl;

    
}