/*input
10
oxooxoxoox
*/

#include <iostream>
#include <vector>

using namespace std;

bool check(int N, int first, int second, vector<int> &array, vector<int> &animals){

	// first is sheep && second sheep
	animals[0] = first;
	animals[1] = second;

	for(int i=2;i<N;i++){
		if(array[i-1] == 0 && animals[i-1] == 0){
			animals[i] = animals[i-2];
		}else if(array[i-1] == 0 && animals[i-1] == 1){
			animals[i] = 1 - animals[i-2];
		}else if(array[i-1] == 1 && animals[i-1] == 0){
			animals[i] = 1 - animals[i-2];
		}else{
			animals[i] = animals[i-2];
		}
	}

	bool result1;
	if(animals[N-1] == 0){ // last is sheep
		if(array[N-1] == 0){
			if(animals[N-2] == animals[0]) result1 = true;
			else result1 = false;
		}else{
			if(animals[N-2] == animals[0]) result1 = false;
			else result1 = true;
		}
	}else{ // last is wolf
		if(array[N-1] == 0){
			if(animals[N-2] != animals[0]) result1 = true;
			else result1 = false;
		}else{
			if(animals[N-2] != animals[0]) result1 = false;
			else result1 = true;
		}
	}

	bool result2;
	if(animals[0] == 0){ // first is sheep
		if(array[0] == 0){
			if(animals[N-1] == animals[1]) result2 = true;
			else result2 = false;
		}else{
			if(animals[N-1] == animals[1]) result2 = false;
			else result2 = true;
		}
	}else{ // first is wolf
		if(array[0] == 0){
			if(animals[N-1] != animals[1]) result2 = true;
			else result2 = false;
		}else{
			if(animals[N-1] != animals[1]) result2 = false;
			else result2 = true;
		}
	}

	return (result1 && result2);
}

void display(vector<int>&animals){
	for(int a:animals){
		if(a == 0){
			cout << "S";
		}else{
			cout << "W";
		}
	}
	cout << endl;
}

int main()
{

	int N;
	string s;

	cin >> N;
	cin >> s;

	vector<int> array(N);
	vector<int> animals(N);
	for(int i=0;i<N;i++){
		if(s[i] == 'o') array[i] = 0;
		else array[i] = 1;
		// cout << array[i] << " ";
	}
	// cout << endl;

	bool result;

	result = check(N, 0, 0, array, animals);
	if(result){
		display(animals);
		return 0;
	}

	result = check(N, 0, 1, array, animals);
	if(result){
		display(animals);
		return 0;
	}

	result = check(N, 1, 0, array, animals);
	if(result){
		display(animals);
		return 0;
	}

	result = check(N, 1, 1, array, animals);
	if(result){
		display(animals);
		return 0;
	}

	cout << (-1) << endl;

	return 0;
}
