A,B,C,X,Y=map(int,input().split())
print(min(min(2*C*max(X,Y),A*X+B*Y),min(2*C*X+B*max(Y-X,0),A*max(X-Y,0)+2*C*Y)))