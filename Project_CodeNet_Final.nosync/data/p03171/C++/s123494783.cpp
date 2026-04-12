#include <iostream>
#include <vector>
using namespace std;


long long int play(vector<int>& seqs){
    int size = seqs.size();

    vector<vector<vector<long long int>> > records = vector<vector<vector<long long int> > >(size, vector<vector<long long int> >(size, vector<long long int>(2, 0)));


    for(int left = size-1; left >= 0; left--)
        for(int right = left; right < size; right++)
            for(int player = 0; player < 2; player++){

                if(left == right){
                    records[left][right][player] = seqs[left];
                    continue;
                }

                int competiter = player ^ 1;
                long long int better;
                long long int get_left = -records[left+1][right][competiter]+seqs[left];
                long long int get_right = -records[left][right-1][competiter]+seqs[right];

    //            if(player == 0)
                    better = max(get_left, get_right);
      //          else
        //            better = min(get_left, get_right);

                records[left][right][player] = better; 
            
                //cout << "l=" << left << " r=" << right << " p=" << player <<" better=" << better << "\n";
            }

    return records[0][size-1][0];
}

int main(){
    int n;
    cin >> n;

    vector<int> seqs(n);

    for(int i = 0; i < n; i++)
        cin >> seqs[i];

    long long int result = play(seqs);  
    cout << result << "\n";

    return 0;
}
