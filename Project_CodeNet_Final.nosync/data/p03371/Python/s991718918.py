A,B,C,X,Y=map(int,input().split())
ans=0
if (A+B)//2>=C:
    ans=2*C*min(X,Y)
    if X>Y:
        if A>2*C:
            ans=ans+2*C*(X-Y)
        else:
            ans=ans+A*(X-Y)
    else:
        if B>2*C:
            ans=ans+2*C*(Y-X)
        else:
            ans=ans+B*(Y-X)
else:
    ans=A*X+B*Y
print(ans)
    