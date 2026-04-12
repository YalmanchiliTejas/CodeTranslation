#include <iostream>
#include <string>
using namespace std;

void swap(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void north(int a[]){
	swap(a,1,4);
	swap(a,4,6);
	swap(a,6,5);
}
void west(int a[]){
	swap(a,1,2);
	swap(a,2,6);
	swap(a,6,3);
}
void east(int a[]){
	swap(a,1,3);
	swap(a,3,6);
	swap(a,6,2);
}
void south(int a[]){
	swap(a,1,5);
	swap(a,5,6);
	swap(a,6,4);
}
void right(int a[]){
	swap(a,2,5);
	swap(a,5,3);
	swap(a,3,4);
}
void left(int a[]){
	swap(a,2,4);
	swap(a,4,3);
	swap(a,3,5);
}

void move(string s, int a[]){
	if(s == "North"){
		north(a);
	}else if(s == "East"){
		east(a);
	}else if(s == "West"){
		west(a);
	}else if(s == "South"){
		south(a);
	}else if(s == "Left"){
		left(a);
	}else {
		right(a);
	}
}

int main(){
	int n;
	while(cin >> n){
		int nums[] = {
			0, 1, 3, 4, 2, 5, 6
		};
		if(n == 0) break;
		int count = 1;
		string s;
		for(int i = 0; i < n; i++){
			cin >> s;
			move(s,nums);
			count += nums[1];
		}
		cout << count << endl;
	}
	return 0;
}