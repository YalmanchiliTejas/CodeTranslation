A,B,C,X,Y = map(int,input().split())
ans = 10**20
for n in range(X+Y):
    ans = min(ans, 2*n*C+A*max(0,(X-n))+B*max(0,(Y-n),0))
print(ans)
