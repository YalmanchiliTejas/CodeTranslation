A,B,C,X,Y = map(int,input().split(" "))
print(min(X*A+Y*B,X*2*C+B*max(0,Y-X),Y*2*C+A*max(0,X-Y)))
