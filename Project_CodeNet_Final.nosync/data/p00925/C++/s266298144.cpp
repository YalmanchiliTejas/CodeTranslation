#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD ((int)1e9+7)

signed  main(){
  stack<int> sta, sta2;
  string s;
  int a = 0, b = 0, r;

  cin>>s>>r;

  //sta.push(s[0] - '0');
  
  for(int i = 0; i < s.size(); i++){//cout<<i<<endl;
    if(s[i] == '+'){//cout<<"+"<<endl;
      sta.push(-1);
    } else if(s[i] == '*'){//cout<<"-"<<endl;
      sta.push(-2);
    } else{
         int temp3 = s[i] - '0';
      if(sta.size() == 0){
	sta.push(temp3);
      } else {
      int temp = sta.top(), temp2;//sta.pop();
      if(temp == -1) {
	sta.pop();
	temp2 = sta.top();sta.pop();
	sta.push(temp2 + temp3);
      } else if(temp == -2){
	sta.pop();
	temp2 = sta.top(); sta.pop();
	sta.push(temp2*temp3);
      } else {
	sta.push(temp3);
	
      }
      }
      //  cout<<sta.top()<<endl;
    }
  }
  
  for(int i = 1; sta.size(); i++){
    b += sta.top(); sta.pop();
  }
  
    
  for(int i = 0; i < s.size(); i++){//cout<<i<<" <-i "<<endl;
    if(s[i] == '+'){//cout<<"+"<<endl;
      // sta.push(-1);
    } else if(s[i] == '*'){//cout<<"-"<<endl;
       sta2.push(-2);
    } else{
      // cout<<"<><><><><><><   "<<endl;
      if(sta2.size() == 0){
	//cout<<"fhdsjklfhdsjlkfhsjflkdshf SIZE -->"<<sta2.size()<<" "<<s[i]-'0'<<endl; 
	sta2.push(s[i] - '0');
      }else {
	//cout<<"[][][][][][][][][][][][][][][][]["<<" "<<sta2.size()<<endl;
		int temp = sta2.top();
	if(temp == -2){
	  sta2.pop();
	  int temp2 = sta2.top(); sta2.pop();
	  //cout<<temp2<<" *  "<<s[i]-'0'<<endl;
	  sta2.push((s[i]-'0')*temp2);
	} else {
	  // cout<<s[i]-'0'<<endl;
	  sta2.push(s[i] - '0');
	}
      }
    }
    
  }
  //cout<<"stack siza ---> "<<sta2.size()<<endl;
 for(; sta2.size();){
    a += sta2.top(); sta2.pop();
  }
    

 //cout<<a<<" "<<b<<endl;

    if(a == r && b == r){
      cout<<'U'<<endl;
    } else if(a == r){
      cout<<'M'<<endl;
    } else if(b == r){
      cout<<'L'<<endl;
    } else {
      cout<<'I'<<endl;
    }
  return 0;
}

