from collections import Counter
n = int(input())
A = [Counter(input()) for i in range(n)]

for i in range(n - 1):
    A[i + 1] = A[i] & A[i + 1]

A2 = sorted(A[-1].most_common())
S = ''
for k, v in A2:
    S += k * v
    
print(S)    