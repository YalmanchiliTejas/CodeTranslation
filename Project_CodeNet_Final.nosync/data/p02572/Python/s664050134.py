N = int(input())
A = list(map(int,input().split()))
a = 0
s = 0
for i in range(N):
    a = (a+A[i])%(10**9+7)
for i in range(N-1):
    a = a-A[i]
    s = (s+A[i]*a)%(10**9+7)
print(s)