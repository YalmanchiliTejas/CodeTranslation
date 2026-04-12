n = int(input())
hs = list(map(int, input().split()))

cnt = 1

for i in range(1, n):
    if max(hs[:i]) <= hs[i]:
        cnt += 1

print(cnt)
