A,B,C,X,Y=map(int,input().split())

ans=10**10
Z=max(X,Y)

for i in range(2*Z+1):
    temp=i*C
    x=max(X-i//2,0)
    y=max(Y-i//2,0)
    temp+=A*x+B*y
    ans=min(ans,temp)
    
print(ans)