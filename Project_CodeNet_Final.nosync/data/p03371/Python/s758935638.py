A,B,C,X,Y = map(int,input().split())
m = max(X,Y)
ans = float('inf')
for i in range(m+1):
    p = i*2*C + max(0,(X-i)*A) + max(0,(Y-i)*B)
    ans = min(ans, p)
print(ans)