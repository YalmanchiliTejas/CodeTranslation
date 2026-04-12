#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string IntToString(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}

int main(){

	while(true){
		int mm[1001]={0};
		string s;
		int m,n;
		cin >> m >> n;
		int num = m;
		int index = 0;

		if(m==0&&n==0){
			break;
		}

		for(int i=1;i<=n;i++){
			cin >> s;
			if(num != 1){
				if(i%3==0 && i%5==0){
					if(s!="FizzBuzz"){
						mm[index] = 1;
						num--;
					}
				}else if(i%3==0){
					if(s!="Fizz"){
						mm[index] = 1;
						num--;
					}
				}else if(i%5==0){
					if(s!="Buzz"){
						mm[index] = 1;
						num--;
					}
				}else{
					if(s!=IntToString(i)){
						mm[index] = 1;
						num--;
					}
				}

				for(int j=index+1;true;j++){
					if(j==m){
						j=0;
					}
					if(mm[j] == 0){
						index = j;
						break;
					}
				}
				
			}
		}

		bool flag = false;
		for(int i=0;i<m;i++){
			if(mm[i]==0){
				if(flag){
					cout << " ";
				}
				cout << i+1;
				flag = true;
			}
		}
		cout << endl;
	}
}