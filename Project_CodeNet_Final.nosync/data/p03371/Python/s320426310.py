A,B,C,X,Y = map(int,input().split())
sum = 0
if A+B > C*2:
    if X > Y:
        sum = Y*2*C
        X = X-Y
        Y = 0
    else :
        sum = X*2*C
        Y = Y-X
        X = 0
if C*2 < A:
    sum = sum + X*2*C
    X = 0
if C*2 < B:
    sum = sum + Y*2*C
    Y = 0
sum = sum + X*A + Y*B
print(sum)