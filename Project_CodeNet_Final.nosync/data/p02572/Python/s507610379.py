N = int(input())
a = list(map(int,input().split()))
ans = 0
total = 0
for i in range(N):
    if i != 0:
        total += a[i-1]
        ans += a[i]*total
print(ans%(10**9 + 7))
