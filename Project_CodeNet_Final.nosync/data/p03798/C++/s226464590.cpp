/*input
10
oxooxoxoox
*/

#include <iostream>
#include <vector>

using namespace std;

bool check_target(const int N, const int target,
	const vector<int> &array, const vector<int> &animals){

	bool result;
	int left = target - 1;
	if(left < 0) left += N;
	int right = (target + 1) % N;

	if(animals[target] == 0){ // last is sheep
		if(array[target] == 0){
			if(animals[left] == animals[right]) result = true;
			else result = false;
		}else{
			if(animals[left] == animals[right]) result = false;
			else result = true;
		}
	}else{ // last is wolf
		if(array[target] == 0){
			if(animals[left] != animals[right]) result = true;
			else result = false;
		}else{
			if(animals[left] != animals[right]) result = false;
			else result = true;
		}
	}

	return result;
}

bool check(const int N, const int first, const int second,
	const vector<int> &array, vector<int> &animals){

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

	bool result1 = check_target(N, N-1, array, animals);
	bool result2 = check_target(N, 0, array, animals);

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
