from itertools import accumulate

N = int(input())

A = [int(x) for x in input().split()]

B = list(accumulate(A))

d = 10**9+7
s = 0

for i in range(N):
    s += (A[i]*(B[-1]-B[i])) % d
    
print(s % d)
