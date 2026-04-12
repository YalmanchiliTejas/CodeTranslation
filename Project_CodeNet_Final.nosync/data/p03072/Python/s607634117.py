N = int(input())
H = list(map(int, input().split()))

hmax = 0
cnt = 0
for h in H:
    if hmax <= h:
        hmax = h
        cnt += 1

print(cnt)
