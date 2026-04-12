A,B,C,X,Y = map(int,input().split())

if X > Y:
    temp = X
    X = Y
    Y = temp
    temp = A
    A = B
    B = temp

if A+B < 2*C:
    print(X*(A+B)+(Y-X)*B)
else:
    if B < 2*C:
        print(2*X*C + B*(Y-X))
    else:
        print(2*X*C + 2*(Y-X)*C)