#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
 
int main(){
	bool flag=true;//下方程序循环判断的标志，如果最大的值小于n的话，那么就结束循环
	ll  ans=0;
 
	vector<ll>ve;
	int n;
	cin>>n;
  ll temporary;
	int position;
	ll x;
	for(int i=0;i<n;i++){
		cin>>x;
		ve.push_back(x);//把数据读入到一个不定长数组里
		
	}
	ll max;
	while(flag){
	max=ve[0];//首先假定第一个元素为最大值
	position=0;//同时也假定最大元素的坐标是0；
	
	for(int i=1;i<n;i++){
	if(ve[i]>max){
		max=ve[i];//开始寻找数组中的最大值，并记录它的位置
	position=i;
	}
	}
	if(max>=n){
	temporary=max/n;//计算减到n以下需要的次数
	ve[position]%=n; 
	ans+=temporary;
	for(int i=0;i<n;i++){
		if(position==i)
			continue;
		ve[i]+=temporary;//把其他的元素加上上边减到n一下需要的次数
	}
	}
	else{
	cout<<ans<<endl;
	flag=false;
	}
	}
return 0;
 
}