n=int(input())
l=list(map(int,input().split()))
c=1
lmax=l[0]
for i in range(1,n):
    if(lmax<=l[i]):
        c+=1 
        if(l[i]>lmax):
            lmax=l[i]
    elif(l[i]>lmax):
        lmax=l[i]
print(c)
