A,B,C,X,Y = map(int,input().split())

if C*2 >= A+B:
    print(A*X+B*Y)
else:
    print(min(C*2*max(X,Y), C*2*min(X,Y) + A*(X-min(X,Y)) + B*(Y-min(X,Y))))
