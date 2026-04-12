A,B,C,X,Y=map(int,input().split())
#AB 
M=max(2*X,2*Y)
ans=10**9
for i in range(0,M+2,2):
    temp=i*C+max(0,X-(i//2))*A+max(0,Y-(i//2))*B
    ans=min(ans,temp)
print(ans)
    