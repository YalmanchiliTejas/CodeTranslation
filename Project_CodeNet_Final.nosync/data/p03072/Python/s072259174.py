n = int(input())
h = list(map(int, input().split()))
cnt = 1

for i in range(1, n):
    flg = True
    for j in range(i):
        if h[i] < h[j]:
            flg = False
            break
    if flg==True:
        cnt += 1
print(cnt)
