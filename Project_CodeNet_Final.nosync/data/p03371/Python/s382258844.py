A,B,C,X,Y=map(int,input().split())

if C*2>A+B:
    print(A*X+B*Y)
else:
    if X>=Y:
        print(C*2*Y+min(A,2*C)*(X-Y))
    else:
        print(C*2*X+min(B,2*C)*(Y-X))