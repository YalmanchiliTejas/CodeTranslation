n=int(input())
c=list(map(int,input().split()))
s=0
for i in range(n):
    d=0
    for j in range(i):
        if c[i]>=c[j]:
            d+=0
        else: 
            d+=1
    if d==0:
        s+=1
    else:
        s+=0
print(s)