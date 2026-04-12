#include<bits/stdc++.h>
/* #include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<stdio.h>
#include<stack>
#include<math.h>
#include<utility>
#include<tuple>
 */
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,n) for(int i=1;i<=(n);i++)
#define brep(i,n) for (int i=n-1;i>=0;i--)
#define LL long long int
 
 /* 
 greater<int>() 
 sortの第三因数に入れて降順 
sqrt(double) √を求める 
pair<int,int> x=make_pair(a,b)
x.first
tuple  get<番目>(変数名)

stack<int> s;//いきどまり
s.push(x) //先頭に入れる
s.pop() //先頭を消す
s.top() //先頭にアクセス
s.empty() //中身があれば0,空なら1
s.size() //中身の数

queue <int> q;//一方通行
q.push(x) //先頭に入れる
q.pop() //先頭を消す
q.front() //先頭にアクセス
q.empty() //中身があれば0,空なら1
q.size() //中身の数

 */
using namespace std;
 
LL lcm(LL n, LL m)
{
	LL u;
	LL ansl = 0;
	for(u=m; u>=m; u++){
		if(u%n == 0){
			if(u%m == 0){
				ansl = u;
				break;
			}
		}
	}
	return ansl;
}
 

int main(){
    int n;
    cin >>n;

    vector<LL>d(n);
    rep(i,n){
        cin >>d[i];
    }
LL now =0;
bool ans=true;
    rep(i,n){
/*         if(now<=d[i]){
            now=d[i];
        }
        */
       now=max(d[i],now);
        if(now<10){
            ans=false;
            break;
        }
        now-=10;
    }
    now=0;
    if(ans==true){
        brep(i,n){
            now=max(d[i],now);
            
            if(now<10){
                ans=false;
                break;
            
            }
            now-=10;
        }
    }
    if (ans==true)cout <<"yes"<<endl;
    else cout <<"no"<<endl;
    return 0;
}
/*
4
20
5
10
1


3
10
5
10


4
20
30
1
20

 */
