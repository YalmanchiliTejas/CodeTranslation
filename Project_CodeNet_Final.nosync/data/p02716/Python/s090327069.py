#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10**7)
from pprint import pprint as pp
from pprint import pformat as pf
# @pysnooper.snoop()
#import pysnooper # debug

import math
#from sortedcontainers import SortedList, SortedDict, SortedSet # no in atcoder
import bisect

class Solver:

    def __init__(self, n, a_s):
        self.n = n
        self.a_s = a_s
        self.extra = 1 if self.n % 2 == 0 else 2
        self.dp = self.prepare_dp()

    def prepare_dp(self):
        dp = [None] * (self.n + 1)
        for i, _ in enumerate(dp):
            dp[i] = [-1 * math.inf] * (1 + self.extra)
        dp[0][0] = 0
        return dp

    def run(self):
        extra = 1 + self.n % 2
        for i, a in enumerate(self.a_s):
            for j in range(self.extra):
                self.dp[i + 1][j + 1] = self.dp[i][j]
            for j in range(self.extra + 1):
                v = self.dp[i][j]
                if (i + j) % 2 == 0:
                    v += a
                self.dp[i + 1][j] = max(self.dp[i + 1][j], v)
        #print('self.dp') # debug
        #print(self.dp) # debug
        return self.dp[n][extra]



if __name__ == '__main__':
    n = int(input())
    a_s = list(map(int, input().split()))
    ans = Solver(n, a_s).run()
    #print('ans') # debug
    print(ans)

    #print('\33[32m' + 'end' + '\033[0m') # debug
