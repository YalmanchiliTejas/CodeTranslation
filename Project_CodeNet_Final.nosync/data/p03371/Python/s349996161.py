A,B,C,X,Y = map(int,input().split())
if X<Y:
    print(min(A*X+B*Y,Y*C*2,X*C*2+B*(Y-X)))
else:
    print(min(A*X+B*Y,X*C*2,Y*C*2+A*(X-Y)))