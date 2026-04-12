#include <bits/stdc++.h>
using namespace std;

//通过vector数组进行模拟
//利用upper_bound()查找其前边比其大的值进行替换为本值
//没有比其大的值就push_back()此值，拿此值作为另一串的开头。

int main ()
{
    int n;
    cin >> n;
    
    vector <int> v;
    while(n--)
    {
    	int x;
        cin >> x;
        x *= -1;
        int it = upper_bound(v.begin(),v.end(),x)-v.begin();
        if(it == v.size()) v.push_back(x);
        else v[it] = x;
        
        //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
        //cout << endl;
    }
    
    cout << v.size()<<endl;
    
	return 0;
}