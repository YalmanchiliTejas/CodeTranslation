#include<bits/stdc++.h>

using namespace std;
#define llu unsigned long long
#define ll long long
#define p pair<int,int>
#define M 1000000007
//sieve can be used here!
bool isPrime(int n){
	if(n==1)return false;//1 is not prime
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
bool myComp(p a,p b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
int row[]={-1,0,1,0};
int col[]={0,-1,0,1};
ll squareRoot(ll x){
	ll low=0;
	ll high=x;
	while(low<=high){
		ll mid= low+(high-low)/2;
		if((mid*mid)>x)high=mid-1;
		else if(mid*mid<x)low=mid+1;
		else return mid;
	}
	return low;
}
void dfs(char par,int r,int c,vector<vector<char>>& arr,vector<vector<bool>>& visited){
	int n=arr.size();
	int m=arr[0].size();
	visited[r][c]=true;
	arr[r][c]=par;
	for(int i=0;i<4;i++){
		int newRow=r+row[i];
		int newCol=c+col[i];
		if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m&&!visited[newRow][newCol]&&arr[newRow][newCol]!='-'){
			if(par=='B') dfs('W',newRow,newCol,arr,visited);
			else dfs('B',newRow,newCol,arr,visited);
		}
	}
}
llu sumDigit(llu x){
	llu ans=0;
	while(x>0){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
llu func(llu a,llu b){
	if(sumDigit(a)==b)return 0;
	llu ans=0;
	llu temp=1;
	while(sumDigit(a)>b){
		int currDigit=((a/temp)%10);
		llu curr=((10-(currDigit))%10)*temp;
		ans+=curr;
		a+=curr;
		temp*=10;
	}
	return ans;
}
ll func(vector<int>&arr){
	int n=arr.size();
	vector<ll> pref(n+1,0);
	for(int i=1;i<=n;i++){
		pref[i]=(pref[i-1]%M+arr[i-1]%M)%M;
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		ll temp=pref[n]-pref[i+1];
		if(temp<0)temp+=M;
		sum+=((temp)*arr[i]%M)%M;
		sum%=M;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<func(arr);
	return 0;
}

