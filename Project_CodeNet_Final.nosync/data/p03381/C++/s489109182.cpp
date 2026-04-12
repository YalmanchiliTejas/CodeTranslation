/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         ·ð×æ±£ÓÓ       ÓÀÎÞBUG
*/
#include<map>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<string.h>
#define mp make_pair
using namespace std;
const int INF=1e9;
int a[200005],n;
int b[200005];
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	int i,j;
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int a1,a2;
	a1=b[n/2-1];
	a2=b[n/2];
	for(i=0;i<n;i++){
		if(a[i]<=a1) cout<<a2<<endl;
		else cout<<a1<<endl;
	}
	return 0;
}