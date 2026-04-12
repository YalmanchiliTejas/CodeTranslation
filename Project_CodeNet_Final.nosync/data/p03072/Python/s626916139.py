n = int(input())
h = list(map(int, input().split()))

maxtall = 0
cnt = 0
for i in range(n):
    maxtall = max(maxtall, h[i])
    if maxtall <= h[i]:
        cnt += 1

print(cnt)