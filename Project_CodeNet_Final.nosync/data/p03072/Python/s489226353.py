N=int(input())
H=list(map(int,input().split()))
if N==1:
    print(1)
else:
    maxh=H[0]
    c=1
    for i in range(1,N):
        if maxh<=H[i]:
            c+=1
            maxh=H[i]
    print(c)