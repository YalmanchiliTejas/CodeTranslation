from itertools import accumulate
n=int(input())
A=[int(i) for i in input().split()]

B=list(accumulate(A))

s = 0 
for i in range(n):
    s += A[i]*(B[-1]-B[i])
    s %= (10**9+7)
print(s)