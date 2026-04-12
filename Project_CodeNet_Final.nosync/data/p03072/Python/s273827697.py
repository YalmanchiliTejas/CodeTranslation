N = int(input())
H = list(map(int,input().split()))
cnt = 1
hmax = H[0]
for i in range(1,N):
    h = H[i]
    if h>=hmax:
        cnt += 1
        hmax = h
print(cnt)