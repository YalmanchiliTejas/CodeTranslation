#include <iostream>
#include <string>

using namespace std;

void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int lFunc(string str){
	
	int num=str.at(0)-'0';

	for(int i=1;i<str.size();i+=2){
		if(str.at(i)=='+'){
			num+=(str.at(i+1)-'0');
		}
		else{
			num*=(str.at(i+1)-'0');
		}
	}

	return  num;
}

int uFunc(string str){
	
	int *dataNum;
	int *dataCal;
	int length = str.size()/2;

	dataNum = new int[str.size()/2+1];
	dataCal = new int[str.size()/2];

	for(int i=0;i<str.size();i++){
		if(i%2==0){
			dataNum[i/2]=str.at(i)-'0';
		}
		else{
			if(str.at(i)=='+'){
				dataCal[i/2]=1;
			}
			else{
				dataCal[i/2]=2;
			}
		}
	}
	/*
	for(int k=0;k<length+1;k++){
		cout<<dataNum[k]<<" ";
	}
	cout<<endl;

	for(int k=0;k<length;k++){
		cout<<dataCal[k]<<" ";
	}
	cout<<endl;
	*/

	while(1){
		int flag=0;

		for(int i=0;i<length;i++){
			if(dataCal[i]==2){
				dataNum[i]*=dataNum[i+1];
				flag=1;

				for(int now=i;now<length-1;now++){
					swap(&dataNum[now+1],&dataNum[now+2]);
					swap(&dataCal[now],&dataCal[now+1]);
				}
				length--;
			}
			/*
			for(int k=0;k<length+1;k++){
				cout<<dataNum[k]<<" ";
			}
			cout<<endl;

			for(int k=0;k<length;k++){
				cout<<dataCal[k]<<" ";
			}
			cout<<endl;
			*/
		}
		if(flag==0)break;
	}

	int num=dataNum[0];
	for(int i=1;i<=length;i++){
		num+=dataNum[i];
	}
//	cout<<"U="<<num<<endl;

	return num;
}

int main(){

	string str;

	cin>>str;

	int input;
	cin>>input;

	if(input==lFunc(str) && input==uFunc(str)){
		cout<<"U"<<endl;
	}
	else if(input == lFunc(str)){
		cout<<"L"<<endl;
	}
	else if(input == uFunc(str)){
		cout<<"M"<<endl;
	}
	else{
		cout<<"I"<<endl;
	}

	return 0;
}