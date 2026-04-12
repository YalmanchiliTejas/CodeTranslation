N = int(input())
H = list(map(int,input().split()))
cnt = 1
hmax = H[0]
for i in range(1,N):
    hmax = max(hmax,H[i-1])
    if H[i]>=hmax:
        cnt += 1
print(cnt)        