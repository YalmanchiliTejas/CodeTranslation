# coding: utf-8
# Your code here!

import sys
readline = sys.stdin.readline
read = sys.stdin.read


#n, *a = [int(i) for i in read().split()]

n = input()
k = int(input())
k += 1
l = len(n)

dp = [[0]*k for _ in range(2)]
dp[0][0] = 1

for c in n:
    ndp = [[0]*k for _ in range(2)]
    ni = int(c)
    for is_less in range(2):
        for num in range(k):
            for d in range(10 if is_less else ni+1):
                if d == 0:
                    ndp[is_less or d < ni][num] += dp[is_less][num]
                elif num < k-1:
                    ndp[is_less or d < ni][num+1] += dp[is_less][num]

    dp = ndp


#print(dp)
print(sum(i[-1] for i in dp))        
        
        
        
        
        
        
        
        
        