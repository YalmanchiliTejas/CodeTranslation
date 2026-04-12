A,B,C,X,Y=map(int,input().strip().split())

ans=A*X+B*Y
Z=0
while max(X,Y)*2>=Z:
    x=max(0,X-(Z//2))
    y=max(0,Y-(Z//2))
    ans=min(ans,A*x+B*y+C*Z)
    Z+=2
print(ans)