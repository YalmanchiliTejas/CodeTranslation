N = int(input())
H = list(map(int,input().split()))
ans = 0
maxheight = 0
for i in range(N):
    if H[i] >= maxheight:
        maxheight = H[i]
        ans+=1
print(ans)
        