N = int(input())
H = list( map(int, input().split()) )

cnt = 1
for i in range(1, N):
    flg = 1
    for j in range(i):
        if H[i] < H[j]:
            flg = 0
    if flg:
        cnt += 1
print(cnt)