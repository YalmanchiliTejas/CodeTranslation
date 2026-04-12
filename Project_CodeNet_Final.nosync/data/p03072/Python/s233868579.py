N = int(input())
H = list(map(int, input().split()))

cnt = 0
m = 0

for h in H:
    if h >= m:
        m = h
        cnt += 1

print(cnt)
