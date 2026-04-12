#95 C
A,B,C,X,Y =map(int,input().split())
honest = A * X + B * Y

if X >= Y:
    diff = C * min(X,Y) * 2 + A * (X-Y)
else:
    diff = C * min(X,Y) * 2 + B * (Y -X)
max_ =C * max(X,Y) * 2

print(min(honest,diff,max_))
