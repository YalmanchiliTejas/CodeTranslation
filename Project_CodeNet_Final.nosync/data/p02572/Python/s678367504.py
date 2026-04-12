import sys
import math
N = int(input())
A = list(map(int, input().split()))

s = 0
d = 0
for j in range(1,N):
    d += A[j]

for i in range(N-1):
    s += d * A[i]
    if s > 10 ** 9 + 7:
        s = s % (10 ** 9 + 7)
    d -= A[i+1]

print(s)
