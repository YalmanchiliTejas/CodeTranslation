N = int(input())
lst = list(map(int, input().split()))
cnt = 0

for i in range(N):
    if i == 0:
        cnt += 1
    else:
        canview = True
        for j in range(0, i):
            if lst[j] > lst[i]:
                canview = False
        if canview:
            cnt += 1
print(cnt)