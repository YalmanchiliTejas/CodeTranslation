A,B,C,X,Y=map(int,input().split())
ans=0
if X>0 and Y>0:
    n=min(X,Y)
    m=min(A+B,2*C)
    X-=n
    Y-=n
    ans+=m*n
ans+=min(A,2*C)*X+min(B,2*C)*Y
print(str(ans))