A,B,C,X,Y = map(int,input().split())
if X-Y>=0:
    print(min(A*X+B*Y,A*(X-Y)+C*2*Y,C*2*X))
else:
    print(min(A*X+B*Y,B*(Y-X)+C*2*X,C*2*Y))