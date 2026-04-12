A,B,C,X,Y = map(int,input().split())

if X>Y:
    A,B,X,Y = B,A,Y,X

if 2*C < B:
    print(C*2*Y)

elif 2*C < A + B:
    print(C*2*X+B*(Y-X))

else:
    print(A*X+B*Y)