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
#            dp[i][j][1]    #なんでもOK
            #0を選ぶとき
            dp[i+1][j][1] += dp[i][j][1]
            #1--9を選ぶとき
            if j+1<=K:
                dp[i+1][j+1][1] += dp[i][j][1]*9

#            dp[i][j][0]    #
            #n == 0 である場合
            if n == 0:
                #nを選ぶしかない
                dp[i+1][j][0] += dp[i][j][0]
            #n != 1 である場合
            else:
                #0 を選ぶとき
                dp[i+1][j][1] += dp[i][j][0]
                #1-(n-1) を選ぶとき
                if j+1<=K:
                    dp[i+1][j+1][1] += dp[i][j][0]*(n-1)
                #n を選ぶとき
                if j+1<=K:
                    dp[i+1][j+1][0] += dp[i][j][0]



    print(dp[L][K][0]+dp[L][K][1])
#    print(dp)

if __name__ == '__main__':
    main()