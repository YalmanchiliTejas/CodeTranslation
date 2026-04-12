N = int(input())
H = list(map(int, input().split()))
cnt = 1
for h in range(1, N):
    flg = True
    for i in range(h):
        if H[i] > H[h]:
            flg = False
    if flg == True:
        cnt += 1
print(cnt)