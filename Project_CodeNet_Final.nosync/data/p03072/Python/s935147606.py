n = int(input())
h = list(map(int, input().split()))

cnt = 1

for i in range(n-1):
    cnt_min = 0
    for j in range(i+1):
        if h[i+1] >= h[j]:
            cnt_min += 1
    if cnt_min == i+1:
        cnt += 1

print(cnt)
