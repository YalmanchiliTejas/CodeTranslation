N = int(input())
A = list(map(int, input().split()))
M = 10**9 + 7
s = 0

sm = sum(A)

for i in range(N):
    sm -= A[i]
    s += sm * A[i]
    s = s % M

print (s)
