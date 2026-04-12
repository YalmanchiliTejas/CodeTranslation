A,B,C,X,Y=map(int,input().split())

ans=[A*X+B*Y,2*C*max(X,Y),2*Y*C+A*max(0,X-Y),2*X*C+B*max(0,Y-X)]
print(min(ans))