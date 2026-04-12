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

const int MAX_N = 60;
long long N, X;

long long all[MAX_N][2];

long long solve(const long long n, const long long x) {
    if (x == 0) { return 0; }
    if (x == 1) { return (n == 0) ? 1 : 0; }

    if (all[n][0] + all[n][1] <= x) { return all[n][0]; }

    long long tmp_idx = 0;
    long long ret = 0;

    tmp_idx++;
    
    if (x < tmp_idx + all[n-1][0] + all[n-1][1]) {
        return solve(n-1, x - tmp_idx);
    }

    tmp_idx += all[n-1][0] + all[n-1][1];
    ret += all[n-1][0];

    if (x == tmp_idx) {
        return ret;
    }

    tmp_idx++; 
    ret++;

    return ret + solve(n-1, x - tmp_idx);
}


main(int argc, char **argv) {
    std::cin >> N >> X;

    all[0][0] = 1;
    all[0][1] = 0;

    for (int i = 1; i <= N; i++) {
        all[i][0] = all[i-1][0] * 2 + 1;
        all[i][1] = all[i-1][1] * 2 + 2;
    }

    //std::cout << "check" << std::endl;

    std::cout << solve(N, X) << std::endl;
}