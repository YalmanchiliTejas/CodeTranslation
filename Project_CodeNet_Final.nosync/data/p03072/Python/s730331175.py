n = int(input())
h = list(map(int, input().split()))
cnt = 0
mh = 0
for i in range(n):
    if mh <= h[i]:
        cnt += 1
    mh = max(mh, h[i])
print(cnt)
