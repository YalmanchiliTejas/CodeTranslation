n = int(input())
hs = list(map(int, input().split()))
max_h = hs[0]
cnt = 0
for i in range(n):
    if max_h <= hs[i]:
        cnt += 1
    max_h = max(max_h, hs[i])
print(cnt)
