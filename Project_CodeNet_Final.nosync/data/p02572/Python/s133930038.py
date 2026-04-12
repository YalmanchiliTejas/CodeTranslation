import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())), dtype = 'object')
mod = 10**9 + 7

sq_sum_a = sum(a)**2
sum_sq_a = sum(a**2)

sum_cross = (sq_sum_a - sum_sq_a) // 2
ans = sum_cross % mod
# xy = ((x + y)**2 - (x**2 + y**2)) // 2

print(ans)