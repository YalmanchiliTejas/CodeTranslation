A,B,C,X,Y=map(int,input().split())
direct=A*X+B*Y
W=min(X,Y)
Z=max(X,Y)
if Z==X:
    E=A
    D=B
else:
    E=B
    D=A
over=Z*C*2
under=W*C*2+(Z-W)*E

print(min(direct,over,under))
    