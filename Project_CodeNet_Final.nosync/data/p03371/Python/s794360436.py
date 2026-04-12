A,B,C,X,Y=map(int,input().split())
#ans=a*A+b*B+ab*C
#a+ab//2>=X
#b+ab//2>=Y
ans=float('inf')
M=max(X,Y)
for ab in range(0,(M+1)*2,2):
    #print(X-ab//2,Y-ab//2,ab)
    ans=min(ans,A*max(0,X-ab//2)+B*max(0,Y-ab//2)+C*ab)
    #print(ans)
print(ans)