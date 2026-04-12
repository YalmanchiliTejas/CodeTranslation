import itertools
N = int(input())
A = list(map(int, input().split()))
z = list(itertools.accumulate(A))
S = 0
for i in range(N-1):
    S += (z[i]*A[i+1])%(10**9+7)
print(S%(10**9+7))