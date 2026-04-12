(A,B,C,X,Y)=[int(i) for i in input().split()]

C*=2
if X>Y:
    print(min([A*X+B*Y,(X-Y)*A+Y*C,C*max([X,Y])]))
else:
    print(min([A*X+B*Y,(Y-X)*B+X*C,C*max([X,Y])]))
