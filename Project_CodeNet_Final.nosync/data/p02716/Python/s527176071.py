import math
import fractions
#import sys
#input = sys.stdin.readline

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    # divisors.sort()
    return divisors

def ValueToBits(x,digit):
    res = [0 for i in range(digit)]
    now = x
    for i in range(digit):
        res[i]=now%2
        now = now >> 1
    return res

def BitsToValue(arr):
    n = len(arr)
    ans = 0
    for i in range(n):
        ans+= arr[i] * 2**i
    return ans

def ValueToArray10(x, digit):
    ans = [0 for i in range(digit)]
    now = x
    for i in range(digit):
        ans[digit-i-1] = now%10
        now = now //10
    return ans
'''
def cmb(n, r, p):
    if (r < 0) or (n < r):
        return 0
    r = min(r, n - r)
    return fact[n] * factinv[r] * factinv[n-r] % p

p = 2
N = 10 ** 6 + 2
fact = [1, 1]  # fact[n] = (n! mod p)
factinv = [1, 1]  # factinv[n] = ((n!)^(-1) mod p)
inv = [0, 1]  # factinv 計算用

for i in range(2, N + 1):
    fact.append((fact[-1] * i) % p)
    inv.append((-inv[p % i] * (p // i)) % p)
    factinv.append((factinv[-1] * inv[-1]) % p)

'''

#a = list(map(int, input().split()))

#################################################
#################################################
#################################################
#################################################

n = int(input())
a = list(map(int, input().split()))

imp = -999999999999999999

dp = [[-1e30,-1e30,-1e30,-1e30] for i in range(n)]
#donthave-Small, donthave-Big, have-Small, have-Big

dp[0][0] = 0
dp[0][1] = imp
dp[0][2] = imp
dp[0][3] = a[0]
dp[1][0] = 0
dp[1][1] = dp[0][3]
dp[1][2] = imp
dp[1][3] = a[1]

for ii in range(n-2):
    i = 2+ii
    must = i//2
    if(i%2==0):
        dp[i][0] = max(dp[i-1][1],dp[i-1][3])
        dp[i][1] = imp
        dp[i][2] = dp[i-1][0] + a[i]
        dp[i][3] = dp[i-1][1] + a[i]
    else:
        dp[i][0] = max(dp[i-1][0],dp[i-1][2])
        dp[i][1] = max(dp[i-1][1],dp[i-1][3])
        dp[i][2] = imp
        dp[i][3] = dp[i-1][0] + a[i]
        
if(n%2==0):
    print(max(dp[-1][1],dp[-1][3]))
else:
    print(max(dp[-1][0],dp[-1][2]))
    
    
    
    
    
    
    
    
    


