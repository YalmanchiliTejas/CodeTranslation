import math
import fractions

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

n,s = list(map(int, input().split()))
a = list(map(int, input().split()))

dp = [[0 for i in range(6002)]for j in range(n+1)]
ans = 0
for i in range(n):
    now = a[i]
    dp[i+1][now] = i+1
    for jj in range(s-1):
        j = jj+1
        dp[i+1][j] += dp[i][j]
        dp[i+1][j+now] += dp[i][j]
        dp[i+1][j] %= 998244353
    ans += dp[i+1][s] * (n - i)
    ans %= 998244353
    #print(ans)


print(ans)






