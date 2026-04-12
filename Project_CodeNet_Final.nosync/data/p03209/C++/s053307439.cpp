#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
    long long x,ans=0;
  	cin>>n>>x;
  
  for(int k=n;k>=0;k-=1){
  	if(x<pow(2,k+1)-1 && x!=1){           //左半分
		x-=1;
    }else if(x==pow(2,k+1)-1){    //中心
		ans+=pow(2,k);
      	break;
    }else if(x==1){               //左端
		break;
    }else if(x==pow(2,k+2)-3){    //右端
		ans+=pow(2,k+1)-1;
      	break;
    }else{                        //右半分
      	ans+=pow(2,k);
      	x-=pow(2,k+1)-1;
    }
  }
		
  cout<<ans<<endl;
}
