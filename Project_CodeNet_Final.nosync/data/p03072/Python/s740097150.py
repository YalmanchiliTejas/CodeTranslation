n = int(input())
h = [int(x) for x in input().split()]

ans = 0
tmp = 0
for i in range(n):
    if max(tmp, h[i]) == h[i]:
        ans += 1
        tmp = h[i]

print(ans)