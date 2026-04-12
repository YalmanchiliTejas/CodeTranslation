N=int(input())
ans=1
a=0
X=[int(i) for i in input().split()]
for i in range(1,N):
    check=True 
    for j in range(0,i):
        if(X[i]<X[j]):
            check=False
            continue
    if(check):
        ans+=1
print(ans)