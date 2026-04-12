A,B,C,X,Y = map(int,input().split())
ave_AB = (A+B)/2
if C >= ave_AB:
    print(X*A+Y*B)
else:
    if X >= Y:
        if 2*C >= A:
            print(2*C*Y+A*(X-Y))
        else:
            print(2*C*X)
    else:
        if 2*C >= B:
            print(2*C*X+B*(Y-X))
        else:
            print(2*C*Y)   