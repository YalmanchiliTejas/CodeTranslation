#!/usr/bin python3
# -*- coding: utf-8 -*-

#import sys
#input = sys.stdin.readline

def main():
    N = input()
    K = int(input())
    L = len(N)
    #dp[i][j][status]   status=0 は小さいのが未確定=i文字まで同じ
    #                   status=1 は小さいことが確定
    #i桁目まで決めて、0でない桁がj個
    #初期値は1 からスタート s=0,i=0,j=0
    dp = [[[0]*2 for j in range(K+1)] for i in range(L+1)]
    dp[0][0][0] = 1
    for i in range(L):
        n = int(N[i])
        for j in range(K+1):
            for st in range(2):
                for x in range(10):
                    i_ = i+1
                    j_ = j
                    st_ = st
                    if x != 0:
                        j_ += 1
                    if j_ > K:
                        continue
                    if st_ == 0 and x > n:
                        continue
                    if st_ == 0 and x < n:
                        st_ = 1
                    dp[i_][j_][st_] += dp[i][j][st]

    print(sum(dp[L][K]))

if __name__ == '__main__':
    main()