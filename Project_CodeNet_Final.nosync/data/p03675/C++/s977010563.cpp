#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int odd_flg = 0;
    if(n%2 == 1)
    {
        odd_flg = 1;
    }
    vector<int> vec(n);
    int j = n/2;
    int count = 1;
    if(odd_flg == 1)
    {
         for(int i = 0; i < n; i++)
        {
           cin >> vec[j];
           if(i%2 == 0)
           {
               j = j + count;
           }else{
               j = j - count;
           }
           count++;
       }
    }else{
        for(int i = 0; i < n; i++)
        {
           cin >> vec[j];
           if(i%2 == 0)
           {
               j = j - count;
           }else{
               j = j + count;
           }
           count++;
       }
        
        
        
    }
    
   
    
    for(int i = 0; i < n; i++)
    {
       cout << vec[i] << " ";
    }
   
    
}
