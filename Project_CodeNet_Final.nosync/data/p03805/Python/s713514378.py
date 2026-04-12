# -*- coding: utf-8 -*-
"""
Created on Sun Aug 26 11:59:46 2018

@author: maezawa
"""

n, m = list(map(int, input().split()))
array = [[0]*n for _ in range(n)]
for i in range(m):
    ai, bi = list(map(int, input().split()))
    array[ai-1][bi-1] = 1
    array[bi-1][ai-1] = 1

#print(array)
#dp = [[-1]*n for _ in range(n)]
done = []

def f(i,done):
    if i in done:
        return 0
    if len(done) == n-1:
        return 1
    if sum(array[i]) == 1 and i != 0:
        return 0
    #if dp[i][j] != -1:
    #    return dp[i][j]
    donecopy = done + [i]
    #print(donecopy)
    ans = sum([f(bi,donecopy) for bi in range(n) if array[i][bi] != 0])
    return ans

print(f(0,done))