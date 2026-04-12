A,B,C,X,Y = map(int,input().split())
ans = min(A*X+B*Y,2*C*min(X,Y)+A*(X-min(X,Y))+B*(Y-min(X,Y)),2*C*max(X,Y) )
print(ans)