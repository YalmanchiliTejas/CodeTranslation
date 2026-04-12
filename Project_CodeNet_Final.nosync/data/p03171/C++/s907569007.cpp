 #include <bits/stdc++.h>
// #include <iostream> 
// #include <sstream> 
// #define int unsigned long long int
using namespace std;
 
 
 
// // bool prime[1000001]; 
 
// // void SieveOfEratosthenes(int n) 
// // { 
// //     // Create a boolean array "prime[0..n]" and initialize 
// //     // all entries it as true. A value in prime[i] will 
// //     // finally be false if i is Not a prime, else true. 
    
// //     memset(prime, true, sizeof(prime)); 
  
// //     for (int p=2; p*p<=n; p++) 
// //     { 
// //         // If prime[p] is not changed, then it is a prime 
// //         if (prime[p] == true) 
// //         { 
// //             // Update all multiples of p greater than or  
// //             // equal to the square of it 
// //             // numbers which are multiple of p and are 
// //             // less than p^2 are already been marked.  
// //             for (int i=p*p; i<=n; i += p) 
// //                 prime[i] = false; 
// //         } 
// //     } 
  
// // }
 
// // long long int fact(int n); 
  
// // long long int nCr(int n, int r) 
// // { 
// //     return fact(n) / (fact(r) * fact(n - r)); 
// // } 
  
// // // Returns factorial of n 
// // long long int fact(int n) 
// // { 
// //    long long int res = 1; 
// //     for (int i = 2; i <= n; i++) 
// //         res = res * i; 
// //     return res; 
// // } 
// // int a[16] = {
// // 	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4
// // };
// // unsigned int g(int k){
// // 	int ab=k&15;
// // 	if(k==0) return 0;
// // 	return a[ab] + g(k>>4);
// // }
 
 
// bool swap(int i, int j, string s, string min){
// 	char t = s[i];
// 	s[i] = s[j];
// 	s[j] = t;
 
// 	if(stoi(min)>stoi(s)) return true;
// 	return false;
// }
 
 
// int main(int argc, char const *argv[])
// {
// 	int t;
// 	int n;
// 	cin>>t;
// 	for (int i = 0; i < t; ++i)
// 	{
// 		cin>>n;
// 		string s,t;
// 		cin>>s>>t;
// 		std::vector<int> v;
// 		for (int j = 0; j < n; ++j)
// 		{
// 			if(s[j]!=t[j]){
// 				v.push_back(j);
// 			}
// 		}
 
// 		if(v.size()==1 || v.size()>2){
// 			cout<<"No"<<endl;
// 			continue;
// 		}
 
// 		int a = v[0];
// 		int b = v[1];
 
// 		if(s[a]==s[b] && t[a]==t[b]){
// 			cout<<"Yes"<<endl;
// 		}else{
// 			cout<<"No"<<endl;
// 		}
 
// 	}
 
// return 0;
// }
 
 
//int dp[6500];
//int a[1000010];
//long long cnt[1000010];
 
// bool f(int c, int n, int m, set<int> &s){
// 	if(c>n) return false;
// 	if(c==n) return true;
 
// 	if(s.find(c)!=s.end()) return false;
 
// 	return f(c+1,n,m,s) || f(c+2,n,m,s) || f(c+3,n,m,s);
// }
//  void printDivisors(int n) 
// { 
//     // Note that this loop runs till square root 
//     for (int i=1; i<=sqrt(n); i++) 
//     { 
//         if (n%i == 0) 
//         { 
//             // If divisors are equal, print only one 
//             if (n/i == i) 
//                 printf("%d ", i); 
  
//             else // Otherwise print both 
//                 printf("%d %d ", i, n/i); 
//         } 
//     } 
// } 
 
  // unsigned long long int sttn(string s){
  // 	int l = s.length();
  // 	unsigned long long int ret = 0;
  // 	for (int i = 0; i < l; ++i)
  // 	{
  // 		if(s[l-1-i]=='1'){
  // 			ret += (unsigned long long int)pow(2,i);
  // 		}
  // 	}
  // 	return ret;
  // }


// string f(int N) 
// { 
  
//     // To store the binary number 
//     unsigned long long int B_Number = 0; 
//     int cnt = 0; 
//     while (N != 0) { 
//         int rem = N % 2; 
//         unsigned long long int c = pow(10, cnt); 
//         B_Number += rem * c; 
//         N /= 2; 
  
//         // Count used to store exponent value 
//         cnt++; 
//     } 
  
//     return to_string(B_Number); 
// }

// void dfs(unordered_set<int,vector<int>>& grp, vector<int>& parent,vector<bool>& visit,int node, vector<int>& count){
// 	visited[node] = true;
// 	count[node] += 
// 	for(auto v: grp[node]){
// 		if(!visited[v]){
// 			parent[v] = node;
// 			dfs(node);
// 		}
// 	}
// }
// unordered_map<int,int> res;
// unordered_map<int,std::vector<int>> mp;

// int f(int i){
// 	if(res.find(i)==res.end()){
// 		// cout<<i<<" inif"<<endl;
// 		// res[i]=0;
// 		bool ff = false;
// 		int x = 0;
// 		for(auto j: mp[i]){
// 			ff=true;
// 			// cout<<"j "<<j<<endl;
// 			x = max(x, f(j));
// 		}
// 		if(ff)res[i] = 1+x;
// 		else res[i]=0;
// 	}
// 	return res[i];
// }
// unordered_map
int main()
{
	
	long long int t;
	// cin>>t;
	t=1;
	
	for(long long int ts=1; ts<=t; ts++){
		long long int n;
		cin>>n;
		std::vector<long long int> a(n,0);
		for(long long int i=0;i<n;i++){
			cin>>a[i];
		}
		// for(auto i: a){
		// 	cout<<i<<" ";
		// }
		// cout<<endl;

		pair<long long int,long long int> dp[n][n];

		for(long long int l=1;l<=n;l++){
			for(long long int i=0;i<=n-l;i++){
				long long int j = i+l-1;
				if(l==1){
					// cout<<a[i]<<endl;
					dp[i][j] = {a[i],0};
					continue;
				}

				long long int f = max(a[i]+dp[i+1][j].second, a[j]+dp[i][j-1].second);
				long long int s = min(dp[i+1][j].first, dp[i][j-1].first);
				dp[i][j] = {f,s};
			}
		}

		// for(int l=1;l<=n;l++){
		// 	for(int i=0;i<=n-l;i++){
		// 		int j = i+l-1;
		// 		cout<<dp[i][j].first<<"/"<<dp[i][j].second<<" ";
		// 	}
		// 	cout<<endl;
		// }

		cout<<(dp[0][n-1].first - dp[0][n-1].second)<<endl;
		
	}
	
    return 0;
}
 
 
 
