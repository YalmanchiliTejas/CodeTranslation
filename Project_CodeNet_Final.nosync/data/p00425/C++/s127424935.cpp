#include<iostream>
#include<string>

using namespace std;

int stand[4];
int side[4];
int ans;

void serch(string s_str)
{
	
	if(s_str=="North")
	{
		int num;
		num=stand[0];
		stand[0]=stand[1];
		stand[1]=stand[2];
		stand[2]=stand[3];
		stand[3]=num;
		side[0]=stand[1];
		side[2]=stand[3];
	}
	else if(s_str=="South")
	{
		int num;
		num=stand[3];
		stand[3]=stand[2];
		stand[2]=stand[1];
		stand[1]=stand[0];
		stand[0]=num;
		side[0]=stand[1];
		side[2]=stand[3];
	}
	else if(s_str=="East")
	{
		int num;
		num=side[1];
		side[1]=stand[0];
		stand[0]=side[3];
		side[3]=stand[2];
		stand[2]=num;
	}
	else if(s_str=="West")
	{
		int num;
		num=side[1];
		side[1]=stand[2];
		stand[2]=side[3];
		side[3]=stand[0];
		stand[0]=num;
	}
	else if(s_str=="Right")
	{
		int num;
		num=side[0];
		side[0]=side[1];
		side[1]=side[2];
		side[2]=side[3];
		side[3]=num;
		stand[1]=side[0];
		stand[3]=side[2];
	}
	else if(s_str=="Left")
	{
		int num;
		num=side[0];
		side[0]=side[3];
		side[3]=side[2];
		side[2]=side[1];
		side[1]=num;
		stand[1]=side[0];
		stand[3]=side[2];
	}
/*	
	cout << "stand:" ;
	for(int i=0;i<4;i++)
		cout << stand[i] <<" " ;
	cout << endl;
	
	cout << "side :" ;
	for(int i=0;i<4;i++)
		cout << side[i] <<" " ;
	cout << endl;
*/	
	ans+=stand[0];
	
	
	return ;
}

int main()
{
	int n;
	string str;
	
	for(;;)
	{
		cin >> n;
		if(n==0)
			break;
		
		stand[0]=1;
		stand[1]=2;
		stand[2]=6;
		stand[3]=5;
		side[0]=2;
		side[1]=3;
		side[2]=5;
		side[3]=4;
		ans=1;
		
//		cout << "now_top:" << stand[0] << endl;
		for(int i=0;i<n;i++)
		{
			cin >> str ;
			serch(str);
//			cout << "now_ans:" << ans << endl;
		}
		
		cout << ans << endl;
	}
}