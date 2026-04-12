A,B,C,X,Y=map(int,input().split())
a1=C*max(X,Y)*2
a2=A*X+B*Y
if X>=Y:
    a3=A*(X-Y)+C*Y*2
else:
    a3=B*(Y-X)+C*X*2
print(min(a1,a2,a3))
