#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
 
int main(){
    string s;
    int n,m,mem,plnum;
    while(1){
        int cnt = 0;
        plnum = 1;
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        bool pl[m+1];
        memset(pl,true,sizeof(pl));
        for(int i=1;i<=n;i++){
            cin >> s;
            if(i % 15 == 0){
	      if(s != "FizzBuzz"){
                pl[plnum] = false;
                cnt++;
	      }
            }
            else if(i % 3 == 0){
	      if(s != "Fizz"){
                cnt++;
                pl[plnum] = false;
	      }
            }
            else if(i % 5 == 0){
	      if(s != "Buzz"){
                cnt++;
                pl[plnum] = false;
	      }
            }
	    else if(i != atoi(s.c_str())){
	      cnt++;
	      pl[plnum] = false;
	    }
            if(m - cnt == 1){
                for(int j=i+1;j<=n;j++) cin >> s;
                break;
            }
            do{
                (plnum == m)? plnum = 1 : plnum++;
            }while(!pl[plnum]);
        }
        for(int i=1;i<=m;i++) {
            if(pl[i]) mem = i;
        }
        for(int i=1;i<=mem;i++){
            if(pl[i]) {
                (i == mem)? cout << i << endl : cout << i << " ";
            }
        }
    }
}