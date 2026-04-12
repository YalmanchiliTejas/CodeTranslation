A,B,C,X,Y =map(int,input().split())
ans = X*A+Y*B
for i in range(max(X,Y)+1):
    now = 2*i*C+max(X-i,0)*A+max(Y-i,0)*B
    ans = min(now,ans)
print(ans)