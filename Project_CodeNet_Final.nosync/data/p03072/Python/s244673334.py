n = int(input())
ls_h = list(map(int, input().split()))

cnt = 0
hmax = 0

for i in range(n):
    if ls_h[i] >= hmax:
        hmax = ls_h[i]
        cnt += 1

print(cnt)