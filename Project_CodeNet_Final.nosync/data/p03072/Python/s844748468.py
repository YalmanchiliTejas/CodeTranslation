N = int(input())
ans = 0
m = 0
a = list(map(int, input().split()))
for i in range(N):
    if m <= a[i]:
        ans += 1
        m = a[i]
print(ans)