n = int(input())
a = list(map(int,input().split()))
m = 1000000007
S = 0
Q = sum(a)
for i in range(n):
    Q -= a[i]
    S += a[i] * Q % m
print(S % m)