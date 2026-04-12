H,W=map(int,input().split())
a=[list(input()) for i in range(H)]
rmidx=[]

for i in range(W):
    cnt=0
    for j in range(1,H):
        if a[0][i]=="." and a[0][i]==a[j][i]:
            cnt+=1
            if cnt==H-1:
                rmidx.append(i)
        else:
            break


for i in range(H):
    for j in reversed(rmidx):
        a[i].pop(j)

rmidx=[]

for i in range(H):
    if a[i].count("#")==0:
        rmidx.append(i)

for i in range(H):
    if not i in rmidx:
        print("".join(a[i]))