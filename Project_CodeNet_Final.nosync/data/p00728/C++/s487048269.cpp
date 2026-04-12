#include<iostream>

using namespace std;

int n;
int score[100];
int bucket[1001] = {0};
int sum_score, ave_score;

void set_score(){
    for(int i=0; i < n; i++){
        cin >> score[i];
    }
}

void sort(){
    for(int i = 0; i < n; i++){
        bucket[score[i]]++;
    }

    for(int i=0,k=0; i < 1001;i++){
        for(int j=0; j<bucket[i]; j++){
            score[k++] = i;
        }
    }
}

void ave(){
    for(int i=1; i < n-1; i++){
        sum_score += score[i];
    }
    ave_score = sum_score/(n-2);
}

void reset(){
    sum_score = 0;
    for(int i=0;i<1001; i++){
        bucket[i] = 0;      
    }
}

int main(void){
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        set_score();
        sort();
        ave();
        cout << ave_score << endl;
        reset();
        
    }
    return 0;
}
