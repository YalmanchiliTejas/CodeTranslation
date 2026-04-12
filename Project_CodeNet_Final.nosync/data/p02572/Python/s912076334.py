import numpy as np
n = int(input())
num_list = list(map(int, input().split()))
mod = int(1e+9+7)
cumsum_list = np.cumsum(num_list[::-1])[::-1][1:]
all_sum = sum(num_list)
score = 0
for i in range(n-1):
    #print(num_list[i], cumsum_list[i])
    score += (num_list[i] * (cumsum_list[i]%mod)) % mod
print(score % mod)