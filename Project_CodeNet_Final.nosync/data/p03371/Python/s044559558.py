A,B,C,X,Y=map(int,input().split())
ans=10**10
Z=max(X,Y)
for i in range(0, Z+1):
    tmp=C*i*2
    if X-i>=0:
        tmp+=A*(X-i)
    if Y-i>=0:
        tmp+=B*(Y-i)
    ans=min(ans,tmp)
print(ans)
