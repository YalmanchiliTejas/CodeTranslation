A,B,C,X,Y = map(int,input().split())
cmin = 10**10
for k in range(max(X,Y)+1):
    n = max(X-k,0)
    m = max(Y-k,0)
    cmin = min(cmin,n*A+m*B+2*k*C)
print(cmin)