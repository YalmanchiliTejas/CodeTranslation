A,B,C,X,Y = map(int,input().split())
a = A*X+B*Y
Z = max(X,Y)
z = min(X,Y)
b = 2*Z*C
if X >= Y:
    c = A*(X-Y)+2*C*Y
else:
    c = B*(Y-X)+2*C*X
print(min(a,b,c))