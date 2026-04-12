A,B,C,X,Y = map(int,input().split())
M = max(X,Y)
m = min(X,Y)
print(min(A*X+B*Y,C*2*m+(M-m)*A if X>Y else C*2*m+(M-m)*B,C*2*M))