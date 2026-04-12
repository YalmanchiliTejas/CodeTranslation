N = int(input())
H = list(map(int,input().split()))
cnt = 0
for i in range(N):
    flg = 1
    height = H[i]
    for j in range(i):
        if H[j] > height:
            flg = 0
            break
    if flg == 1:
        cnt += 1
print(str(cnt))