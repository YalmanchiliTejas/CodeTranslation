N = int(input())
H = list(map(int, input().split()))

cnt = 0
for i in range(N):
    if (i == 0) :
        cnt = cnt + 1
    else :
        if (max(H[0:i]) <= H[i]) :
            cnt = cnt + 1

print(cnt)
