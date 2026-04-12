A,B,C,X,Y=map(int,input().split(' '))
print(min(A*X+B*Y,2*C*max(X,Y),2*C*min(X,Y)+A*max(0,X-Y)+B*max(0,Y-X)))