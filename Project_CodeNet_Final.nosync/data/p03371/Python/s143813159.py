A,B,C,X,Y = map(int,input().split())
C*=2
ans = min(X*A+Y*B,C*max(X,Y))
ans = min(X*C+max(0,Y-X)*B,Y*C+max(0,X-Y)*A,ans)

print(ans)