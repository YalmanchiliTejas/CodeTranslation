N=int(input())
H=list(map(int,input().split()))

at=1
hmax=H[0]
for i in range(1,N):
    if hmax <= H[i]:
        hmax=H[i]
        at+=1


print(at)
