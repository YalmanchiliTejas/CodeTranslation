import numpy
N = int(input())
A = list(map(int, input().split()))

res = []
res.append(A[0])
for i in range(len(A)-1):
    res.append(res[i] + A[i+1])

sum = 0
for i in range(N-1):
    sum += A[i] * (res[N - 1] - res[i])

print(sum % (10**9+7))