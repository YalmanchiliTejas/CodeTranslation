#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

 

//(a+b)%c=(a%c+b%c)%c
//(a*b)%c=((a%c)*(b%c))%c
/*ll binaryToDecimal(ll n) 
{ 
    ll num = n; 
    ll dec_value = 0; 
  
    
    ll base = 1; 
  
    ll temp = num; 
    while (temp) { 
        ll last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 

}    
ll countSetBits(ll n) 
{ 
    if (n == 0) 
        return 0; 
    else
        return 1 + countSetBits(n & (n - 1)); 
} */
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
	

    string s;
    cin>>s;int a=0;int b=0;
    for(int i=0;i<3;i++){
        if(s[i]=='A')a++;
    }
    for(int i=0;i<3;i++){
        if(s[i]=='B')b++;
    }
    if(a*b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
    }
    
    
    
	