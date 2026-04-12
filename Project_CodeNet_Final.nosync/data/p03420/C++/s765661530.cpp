#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_N = 100050;
int N, K;

int main(int argc, char **argv) {
    std::cin >> N >> K;
    long long ret = 0;
    /*
    for (int b = K + 1; b <= N; b++) {
        int n = (N - K) / b;
        ret += n + 1;
    }
    std::cout << ret << std::endl;
    */
    if (K == 0) {
        std::cout << (long long) N * N << std::endl;
        return 0;
    }

    for (long long b = 1; b <= N; b++) {
        if (K >= b) { continue; }
        long long n = (N - K) / b;
        ret += n * (b - K);
        //std::cout << b << " " << n << " " << n * (b - K) << std::endl;
        if (n*b < N) {
            for (long long res = K; res < b; res++) {
                if (n*b + res <= N) { 
                    ret++;
                }
                else { break; }
            }
        }
    }

    std::cout << ret << std::endl;
    
    return 0;

}