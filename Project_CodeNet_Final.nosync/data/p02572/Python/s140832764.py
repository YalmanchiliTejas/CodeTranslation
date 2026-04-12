n = int(input())
a = list(map(int,input().split()))

ans = 0
b = [0] * n
c = 0

for i in range(n):
    c = c + a[i]
    b[i] = c

for j in range(n-1):
    ans = (a[j] * (b[n-1] - b[j]) + ans) % (10**9+7)

print(ans)
