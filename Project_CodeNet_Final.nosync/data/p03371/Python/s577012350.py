A,B,C,X,Y = map(int,input().split())

if X>Y:
    print(min( A*X+B*Y , 2*C*X , 2*C*Y+A*(X-Y)))
else:
    print(min( A*X+B*Y , 2*C*Y , 2*C*X+B*(Y-X)))
