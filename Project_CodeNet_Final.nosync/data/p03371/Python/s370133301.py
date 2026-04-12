A,B,C,X,Y = map(int,input().split())

if C > (A+B)/2:
    print(A*X+B*Y)
elif X > Y and C > A/2:
    print(C*Y*2+A*(X-Y))
elif X > Y:
    print(C*X*2)
elif C > B/2:
    print(C*X*2+B*(Y-X))
else:
    print(C*Y*2)