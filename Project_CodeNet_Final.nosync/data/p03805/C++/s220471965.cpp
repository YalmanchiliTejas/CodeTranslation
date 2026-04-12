#include<iostream>
using namespace std;
void swap(int *a, int *b){
	int temp; temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort_sub_inv(int *data, int left, int right){
	int right_flag = right;
	int left_flag = left;
	int pivot = data[(right + left) / 2];
	int *data_right_flag;
	int *data_left_flag;

	while(right_flag >= left_flag){
		for(; data[right_flag] < pivot; right_flag --){
			if(right_flag == left){
				break;
			}
		}

		for(; data[left_flag] > pivot; left_flag ++){
			if(left_flag == right){
				break;
			}
		}

		if(right_flag >= left_flag){
			data_right_flag = data + right_flag;
			data_left_flag = data + left_flag;
			swap(data_right_flag, data_left_flag);
			right_flag --;
			left_flag ++;
		}
	}

	if(right_flag > left){
		quick_sort_sub_inv(data, left, right_flag);
	}
	if(left_flag < right){
		quick_sort_sub_inv(data, left_flag, right);
	}
}

void quick_sort_inv(int *data, int data_size){
	quick_sort_sub_inv(data, 0, data_size - 1);
}

int fact(int n){
	if(n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

int* del(int *array, int point, int size){
	int i;
	for(i = point; i < size - 1; i ++){
		array[i] = array[i + 1];
	}

	return array;
}

int *jisho(int *array, int num, int size){
	int keisu[size];
	--num;

	for(int i = size - 1;  i >= 0; --i){
		keisu[i] = num / fact(i);
		num = num % fact(i);
	}

	int flag[size];
	
	for(int i = size - 1; i >=  0; --i){
		flag[i] = array[keisu[i]];
		del(array, keisu[i], i + 1);
	}

	for(int i = 0; i < size; ++i)
		array[i] = flag[i];
	
	return array;

}

int main(){
	int n, m;
	cin >> n >> m;

	int load[m][2];

	for(int i = 0; i < m; ++i)
		cin >> load[i][0] >> load[i][1];

	int count = 0;
	int array[n];
	bool judge = 0;
	for(int i = 0; i < n; ++i)
		array[i] = i + 1;

	for(int i = 1; i <= fact(n - 1); ++i){	
		for(int y = 0; y < n; ++y)
			array[y] = y + 1;

		jisho(array + 1, i, n - 1);

			/*		for(int y = 0; y < n; ++y)
						cout << array[y];
					cout << endl;*/
		for(int j = 0; j < n - 1; ++j){
			for(int k = 0; k < m; ++k){
				if((array[j] == load[k][0] && array[j + 1] == load[k][1]) || (array[j] == load[k][1] && array[j + 1] == load[k][0])) {
					judge = 1;
					//if(array[0] == 1 && array[1] == 6 && array[2] == 7 && array[3] == 5 && array[4] == 4 && array[5] == 2 && array[6] == 3)
					//	cout << array[j] << ", " << array[j + 1] << endl;
					break;
				}
			}
			if(judge == 0)
				break;
			else{
				judge = 0;
				if(j == n - 2){
					++count;
				/*	for(int y = 0; y < n; ++y)
						cout << array[y];
					cout << "OK!" << endl;*/
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}