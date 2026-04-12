N = int(input())
H = list(map(int,input().split()))

cnt = 1
maxheight = H[0]
for i in range(1,N):
        if H[i] >= maxheight:
                cnt += 1
                maxheight = H[i]

print(cnt)