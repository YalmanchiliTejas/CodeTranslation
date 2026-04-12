N = int(input())
H = list(map(int,input().split()))

ans =1
for i in range(1,N,1):
    muri = False
    for j in range(0,i,1):
        if H[i]<H[j]:
            muri = True
    if not muri:
        ans+=1

print(ans)