#include <iostream>
#include <algorithm>
using namespace std;

int calc(char met, double nenri, int com, int money, int years){
   if(met=='0'){
       int total_risi=0;
       for(int i=0 ; i < years ; i++){
           total_risi += money * nenri;
           money -= com;
       }
       return(money+total_risi);
   }
   else if(met=='1'){
       for(int i=0 ; i < years ; i++){
          money = money + money * nenri - com;
       }
       return money;
   }
   else cout << "error!!" << endl;
}

int main(){
    int m;
    cin >> m;
    while(m>0){
        int money,years,n,ans=0;
        cin >> money >> years >> n;
        for(int i=0 ; i<n ; i++){
            char m; double n; int c;
            cin >> m >> n >> c;
            ans = max(calc(m,n,c,money,years),ans);
        }
        cout << ans << endl;
        m--;
    }
}