N = int(input())
H = list(map(int, input().split()))

maxh = 0
cnt = 0

for a in H:
    if maxh <= a:
        cnt += 1
        maxh = max(maxh, a)
print(cnt)
