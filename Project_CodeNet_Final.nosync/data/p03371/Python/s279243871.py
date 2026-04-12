A,B,C,X,Y = map(int,input().split())
print(min(A*X+B*Y,2*C*X+B*max(0,Y-X),2*C*Y+A*max(0,X-Y)))