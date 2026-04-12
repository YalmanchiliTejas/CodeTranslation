A,B,C,X,Y = list(map(int,input().split()))
if A+B <= 2*C:
    print(A*X+B*Y)
    exit()
if X == Y:
    print(2*C*X)
elif X > Y:
    tmp = 2*C*Y
    X -= Y
    m = min(2*C*X,A*X)
    print(tmp+m)
else:
    tmp = 2*C*X
    Y -= X
    m = min(2*C*Y,B*Y)
    print(tmp+m)