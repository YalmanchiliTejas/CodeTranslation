from sys import stdin
N = int(stdin.readline())
A = sorted([int(stdin.readline()) for i in range(N)])

a = [0] * N
b = [0] * N
j = 1

for i in range(N-1):
    a[i] += -j
    a[i+1] += j
    b[i] += j
    b[i+1] += -j
    j = -j

a.sort()
b.sort()
s1 = s2 = 0
for i in range(N):
    s1 += a[i] * A[i]
    s2 += b[i] * A[i]
print(max(s1, s2))