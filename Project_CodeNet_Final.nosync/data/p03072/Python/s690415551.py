# B - Great Ocean View

n = int(input())
h = list(int(x) for x in input().split())

ans = 0
tmp = 0
for i in range(n):
    if tmp <= h[i]:
        ans += 1
        tmp = h[i]
    else:
        continue

print(ans)