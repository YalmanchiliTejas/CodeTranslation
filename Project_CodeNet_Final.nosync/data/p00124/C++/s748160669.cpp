#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    int flag=0;
    while(cin >> n && n)
    {
    	string str;
    	int a,b,c;
    	vector<string>list;
    	int num[1000]={};
    	int numberlist[1000]={};
    	int count=0;

    	while(n--)
    	{
    		cin >> str >> a >> b >> c;
    		num[count]=a*3+c;
    		numberlist[count]=count;
    		list.push_back(str);
    		count++;
    	}

    	for(int i=0;i<count;i++)
    	{
    		for(int j=i;j<count;j++)
    		{
    			if(num[i]<num[j])
    			{
    				swap(num[i],num[j]);
    				swap(list[i],list[j]);
    				swap(numberlist[i],numberlist[j]);
    			}
    		}
    	}
    	for(int i=0;i<count;i++)
    	{
    		for(int j=i;j<count;j++)
    		{
    			if( num[i]==num[j] && numberlist[i]>numberlist[j])
    			{
    				swap(num[i],num[j]);
    				swap(list[i],list[j]);
    				swap(numberlist[i],numberlist[j]);    			
    			}
    		}
    	}
    	if(flag)cout << endl;
    	for(int i=0;i<count;i++)
    	{
    		cout << list[i] << "," << num[i] << endl;
    	}
    	flag=1;
    }
    return 0;
}