N = int(input())
H = list(map(int, input().split()))

cnt = 0
max_h = 0
for h in H:
    if h >= max_h:
        cnt += 1
        max_h = h
print(cnt)
