n=int(input())
l=list(map(int,input().split()))
c=1
f=True
for i in range(1,n):
    f=True
    for j in range(i,0,-1):
        if l[j-1]>l[i]:
            f=False
    if f:
        c+=1
print(c)