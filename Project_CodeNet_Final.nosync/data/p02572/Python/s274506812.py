import numpy
N = int(input())
A = list(map(int, input().split()))
A_sum = numpy.cumsum(A)
ans = 0
for idx in range(len(A)):
    ans += A[idx] * int(A_sum[-1]-A_sum[idx])
print(ans % (10**9+7))
