# coding: utf-8
# Your code here!
import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
read = sys.stdin.read


n,s,*a = [int(i) for i in read().split()]
MOD = 998244353
 

def mul(c,m,dp): #multiply (1-x^c) up to x^m
    for i in range(m,c-1,-1):
        dp[i] += dp[i-c]
        dp[i] %= MOD
 
dp = [0]*(s+1)

ans = 0
for c in a:
    dp[0] += 1
    mul(c,s,dp)
    ans += dp[s]
    #print(dp)    

print(ans%MOD)    


    