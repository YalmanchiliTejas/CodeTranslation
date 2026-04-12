import numpy as np
n = int(input())
a = list(map(int,input().split()))
a_sum = sum(a)
aa = np.array(np.cumsum(a),dtype="object")
all_a = sum(a)

mod = 1000000007

ans = 0
for i in range(n-1):
    ans += (a[i]%mod * (all_a - aa[i])%mod)

print(ans%mod)