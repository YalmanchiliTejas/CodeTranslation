#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;

const int MOD = 1e9+7;

signed main(){

	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    #endif
   
  int n;
  cin>>n;

  int tot  = 0;

  vector<int>v(n);

  for(int i=0;i<n;i++){
    cin>>v[i];
    tot += v[i];
  }

  int ans =0;
  for(int i=0;i<n;i++){
     tot-=v[i];
     ans = (ans%MOD + (tot %MOD *v[i] % MOD) %MOD)%MOD;
     
    // cout<<ans<<endl;
  }
  cout<<ans<<endl;

	return 0;

} 







// string codes[] = {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

// vector<string> fx(string s){


// 	if(s == ""){

// 	   vector<string> y;
// 	   y.push_back("");
// 	   return y;
// 	}

//     //678
// 	char ch = s[0];
// 	//78
// 	string rem = s.substr(1);
    
//     vector<string> temp = fx(rem);
    
//     vector<string> myans ;
   
//     for(int j=0;j<codes[ch-'0'].length();j++){
//     	 for(int i=0;i<temp.size();i++){
//               myans.push_back(codes[ch-'0'][j] + temp[i]);
//           }
//     }

//     return myans;
   
// }


// vector<string> path(int n){
    
//     if(n == 0){
//     	vector<string> v;
//     	v.push_back("");
//     	return v;
//     }else if(n < 0){
//     	vector<string>v;
//     	return v;
//     }

// 	vector<string>ans1 = path(n-1);
// 	vector<string>ans2 = path(n-2);
// 	vector<string>ans3 = path(n-3);

// 	vector<string> fans;

// 	for(int i=0;i<ans1.size();i++){
// 		ans1[i] = '1' + ans1[i];
// 		fans.push_back(ans1[i]);
// 	}

// 	for(int i=0;i<ans2.size();i++){
// 		ans2[i] = '2' + ans2[i];
// 		fans.push_back(ans2[i]);
// 	}

// 	for(int i=0;i<ans3.size();i++){
// 		ans3[i] = '3' + ans3[i];
// 		fans.push_back(ans3[i]);
// 	}


// 	return fans;
// }

// vector<string> getPath(int sr,int sc,int dr,int dc){

//     if(sr == dr and sc == dc){
//     	vector<string> v;
//     	v.push_back("");
//     	return v;
//     }else if(sr > dr or sc > dc ){
//     	vector<string> v;
//     	return v;
//     }

// 	vector<string> ch1 = getPath(sr,sc+1,dr,dc);
// 	vector<string> ch2 = getPath(sr+1,sc,dr,dc);
    
//     vector<string> ans;

// 	for(int i=0;i<ch1.size();i++){
// 		ch1[i] = 'H' + ch1[i];
// 		ans.push_back(ch1[i]);
// 	}

// 	for(int i=0;i<ch2.size();i++){
// 		ch2[i] = 'V' + ch2[i];
// 		ans.push_back(ch2[i]);
// 	}

// 	return ans;
// }


// //ABC
// vector<string> getSub(string s){

   
//    if(s == ""){
//    	  vector<string> v;
//    	  v.push_back("");
//    	  return v;
//    }

//    //A
// 	char x = s[0];
//    //BC
// 	string rem = s.substr(1);
    
//     // 4 strings
// 	vector<string> temp = getSub(rem);
    
//     vector<string>res;

//     for(int i=0;i<temp.size();i++){
      
//       res.push_back(x+temp[i]);
//       res.push_back("_"+temp[i]);
//     }

//     return res;
// }


// void permute(string x,string y){
   
//    if(x == ""){
//    	 cout<<y<<" ";
//    	 return ;
//    }

// 	for(int i=0;i<x.length();i++){

// 		char choose = x[i];

// 		string rem = x.substr(0,i) + x.substr(i+1);

// 		permute(rem,y+choose);
// 	}
// }

// int chess[5][5];
// const int n=5;

// void printChess(){
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cout<<chess[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	cout<<endl;
// }



// void knightstour(int r,int c,int chess[][n],int moves){
   
//     if(r<0 or c <0 or r>=n or c>=n or chess[r][c] != 0 ){
//     	return;
//     }else if(moves == n*n){
        
//         chess[r][c] = moves;
//         printChess();
//         chess[r][c] = 0;

//         return;
//     }

//     chess[r][c] = moves;

// 	knightstour(r-2,c+1,chess,moves+1);
// 	knightstour(r-1,c+2,chess,moves+1);
// 	knightstour(r+1,c+2,chess,moves+1);
// 	knightstour(r+2,c+1,chess,moves+1);
// 	knightstour(r-2,c-1,chess,moves+1);
// 	knightstour(r-1,c-2,chess,moves+1);
// 	knightstour(r+1,c-2,chess,moves+1);
// 	knightstour(r+2,c-1,chess,moves+1);

// 	chess[r][c] = 0;
// }

