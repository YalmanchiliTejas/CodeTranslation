n = int(input())
h = list(map(int, input().split()))

ans = 1

for i in range(1,n):
    lh = max(h[0:i])
    if h[i] >= lh:
        ans += 1

print(ans)