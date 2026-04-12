n = int(input())
h = list(map(int, input().split()))
ans = 1

for i in range(1, n):
    if h[0] <= h[i] and max(h[:i]) <= h[i]:
        ans += 1

print(ans)