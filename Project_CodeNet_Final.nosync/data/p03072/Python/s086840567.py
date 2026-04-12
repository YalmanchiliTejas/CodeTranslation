n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(1, n):
    l = h[:i]
    if h[i] >= max(l):
        ans += 1
print(ans)