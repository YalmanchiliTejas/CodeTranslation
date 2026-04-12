A,B,C,X,Y = map(int,input().split())

if A+B<=2*C:
    print(A*X+B*Y)
else:
    if X>=Y:
        print(2*C*min(X,Y)+min(2*C*(X-Y),A*(X-Y)))
    else:
        print(2*C*min(X,Y)+min(2*C*(Y-X),B*(Y-X)))