import numpy as np
N = int(input())
A_str = input()
A_str_list = A_str.split()
A = np.array([int(A_str_list[i]) for i in range(N)])
sum = 0
mod = 1000000007
res = np.cumsum(A)
res = [np.mod((res[-1]-res[i]), mod) for i in range(N)]
# print(res)
for i in range(N):
    sum += np.mod(res[i]*A[i], mod)
print(np.mod(sum, mod))