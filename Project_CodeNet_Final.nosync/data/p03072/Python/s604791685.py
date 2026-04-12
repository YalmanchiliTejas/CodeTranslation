n = int(input())
hs = list(map(int, input().split(" ")))
ans = 0
for i in range(n):
    ans += hs[i] == max(hs[:i + 1])
print(ans)
