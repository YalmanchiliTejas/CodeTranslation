N = int(input())
H = list(map(int, input().split()))

cnt = 0
m = 0
for h in H:
    m = max(m, h)
    if h>=m:
        cnt += 1
print(cnt)