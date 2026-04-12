A,B,C,X,Y = map(int, input().split())
ans = 5000 * 10**5 * 4 + 1
for c in range(0,max(X,Y)*2+1,2):
    a = c * C
    x,y = max(0,X-c//2), max(0,Y-c//2)
    a += A*x + B*y
    ans = min(ans, a)

print(ans)