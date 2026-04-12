h,w=map(int,input().split())
a=[input() for i in range(h)]
b=[i for i in a if i.count("#")>0]
for i in range(w-1,-1,-1):
    if sum([b[j][i]=="#" for j in range(len(b))])==0:
        for k in range(len(b)):
            b[k]=b[k][:i]+b[k][i+1:]
print(*b,sep="\n")