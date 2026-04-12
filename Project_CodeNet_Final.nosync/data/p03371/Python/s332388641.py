A,B,C,X,Y=map(int,input().split())

if A+B<=2*C:
    ans=A*X+B*Y

elif X<=Y:
    ans=2*X*C
    Y-=X
    ans+=min(2*Y*C,Y*B)

elif X>Y:
    ans=2*Y*C
    X-=Y
    ans+=min(2*X*C,X*A)

print(ans)