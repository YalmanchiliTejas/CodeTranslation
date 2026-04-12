N = int(input())
H = list(map(int, input().split()))
res = 0
cnt = 0
for h in H:
    if h < res:
        continue
    cnt += 1
    res = h
print(cnt)