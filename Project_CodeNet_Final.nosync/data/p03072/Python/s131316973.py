N = int(input())
Hs = list(map(int, input().split()))

max_h = 0
cnt = 0
for n in range(0, N):
    if Hs[n] >= max_h:
        max_h = Hs[n]
        cnt += 1
print(cnt)