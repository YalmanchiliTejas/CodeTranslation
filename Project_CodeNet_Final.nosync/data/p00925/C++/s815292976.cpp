#include<iostream>
#include<stack>
#include<string>
using namespace std;

char dealing(string str,int test)
{
	int len = str.length();
	stack<int> num;
	stack<char> yun;
	for(int i=len-1;i>=0;--i)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			int j = i;
			int sum = 0;
			int by = 1;
			while(j>=0)
			{
				if(str[j]>='0'&&str[j]<='9')
				{
					sum+=by*(str[j]-'0');
					by*=10;
					j--;
				}
				else{
					i =j+1;
					break;
				}
			}
			num.push(sum);
			if(j<0)
			break;
		}
		else
			yun.push(str[i]);
		
	}
	
	int result_left_to_right =0;
	int result_normal = 0;
	
		stack<int> num_copy(num);
	stack<char> yun_copy(yun);
	
	int num_len = num.size();
	result_left_to_right  = num.top();
	num.pop();
	

	
	
	for(int i=1;i<num_len;++i)
	{
		char cc = yun.top();
		yun.pop();
		int num1 = num.top();
		num.pop();
		if(cc=='+')
		result_left_to_right +=num1;
		else
		result_left_to_right *=num1;
	}
	
	//cout<<result_left_to_right <<endl;
	
	stack<int> result_nor;
	
	int q= num_copy.top();
	num_copy.pop();
	
	for(int i=1;i<num_len;++i)
	{
		char cc;
		cc = yun_copy.top();
		yun_copy.pop();
		
		int num1 = num_copy.top();
		num_copy.pop();
		
		
		if(cc=='*')
		q = q*num1;
		else
		{
			result_nor.push(q);
			q = num1;
		}
		
	}
	result_nor.push(q);
	int sizes = result_nor.size();
	for(int i=0;i<sizes;++i){
		result_normal+=result_nor.top();
		result_nor.pop();
	}
	
//cout<<"test"<<result_normal<<endl;
	
	
	if(test==result_left_to_right&&test!=result_normal)
		return 'L';
	if(test!=result_left_to_right&&test==result_normal)
	return 'M';
	if(test==result_left_to_right&&test==result_normal)
	return 'U';
	if(test!=result_left_to_right&&test!=result_normal)
	return 'I';
	return 'I';
}

int main()
{
	string str;
	int num;
	cin>>str;
	cin>>num;
	cout<<dealing(str,num)<<endl;
	
	return 0;
	
	
}