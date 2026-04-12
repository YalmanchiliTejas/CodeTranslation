#cやり直し
import numpy
n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = 10**9 +7

before = a[-1]
for i in range(n-1,0,-1):
    
    ans += (a[i-1]*before)%mod
    before += a[i-1]
    
print(ans%mod)