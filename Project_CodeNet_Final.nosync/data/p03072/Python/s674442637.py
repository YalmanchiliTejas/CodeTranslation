n = int(input())
h = [int(item) for item in input().split()]

mx = -float("inf")

ans = 0
for i in range(n):
    if h[i] >= mx:
        mx = h[i]
        ans += 1

print(ans)
