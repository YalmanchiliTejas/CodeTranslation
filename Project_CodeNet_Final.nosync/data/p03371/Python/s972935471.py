A,B,C,X,Y=map(int,input().split())

ans=10**12
for i in range(max(X,Y)+1):
    cnt=0
    cnt+=i*C*2
    cnt+=max(0,X-i)*A
    cnt+=max(0,Y-i)*B
    ans=min(ans,cnt)
print(ans)