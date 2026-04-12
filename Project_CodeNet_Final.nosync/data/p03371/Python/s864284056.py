A,B,C,X,Y = map(int,input().split())
C*=2
ans = min(A*X+B*Y,C*max(X,Y))
ans = min(ans,C*min(X,Y)+(A*(X-Y) if X>Y else B*(Y-X)))
print(ans)