n = int(input())
Hs = list(map(int, input().split()))
m = -50
cnt = 0

for i in range(n):
    if Hs[i] >= m:
        m = Hs[i]
        cnt += 1
print(cnt)

