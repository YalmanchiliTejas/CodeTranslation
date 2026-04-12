N = int(input())
H = list(map(int, input().split()))
Hr = H[::-1]
cnt = 0


for i in range(N):
    flg = True
    for j in range(i+1, N):
        if Hr[i] < Hr[j]:
            flg = False
            break
    if flg == True:
        cnt += 1

print(cnt)
