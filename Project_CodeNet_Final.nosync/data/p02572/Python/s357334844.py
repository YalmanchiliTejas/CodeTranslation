N = int(input())
A = list(map(int, input().split()))
s = 0
a = 0
for i in range(N-1, 0, -1):
    s = (s+A[i])%(10**9+7)
    a = (a+A[i-1]*s)%(10**9+7)
print(a)
