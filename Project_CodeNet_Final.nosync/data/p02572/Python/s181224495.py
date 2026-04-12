n = int(input())
a = list(map(int,input().split()))
s = sum(a)
S = 0
for i in range (n):
    s -=a[i]
    S += a[i] * s
ans = S%(10**9+7)
print(int(ans))