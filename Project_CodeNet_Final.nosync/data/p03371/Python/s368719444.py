A,B,C,X,Y = map(int,input().split())

ans=[(A*X+B*Y),
    C*2*X+B*max(0,(Y-X)),
    C*2*Y+A*max(0,(X-Y))]
print(min(ans))
