//的場梨沙★担当
//結城晴★副担当
//日野茜★副担当
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <cctype>
#include <complex>
#include <regex>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdio.h>


using namespace std;

int main(void) {

        int N;
        cin>>N;
        int A=1;
        vector<int >H(N);
        for(int i=0;i<N;i++){
            cin>>H[i];
        }
        int B=H[0];
        for(int i=1;i<N;i++){
            if(H[i]>=B){
                A++;
                B=H[i];
            }
        }

        cout<<A<<endl;

}
