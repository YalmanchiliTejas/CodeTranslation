A,B,C,X,Y=map(int,input().split())

ans=10**10
for i in range(max(X,Y)+1):
    cnt=0
    cnt+=C*2*i
    x=X-i
    y=Y-i
    cnt+=max(0,x*A)
    cnt+=max(0,y*B)
    if ans>cnt:
        ans=cnt
print(ans)