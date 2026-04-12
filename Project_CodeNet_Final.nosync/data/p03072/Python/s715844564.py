n = int(input())
h = list(map(int, input().split()))

ans = 0
mx = h[0]
for i in range(n):
    if h[i] >= mx:
        ans = ans + 1
        mx = h[i]
print(ans)