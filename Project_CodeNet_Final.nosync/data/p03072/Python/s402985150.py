N = int(input())
H = list(map(int, input().split()))
cnt = 0
for i in range(N):
    flg = 0
    for j in range(i):
        if H[i] < H[j]:
            flg = 1
            break
    if flg == 1:
        continue
    cnt += 1
print(cnt)