A,B,C,X,Y = map(int, input().split())
ans = float('inf')
for i in range(0,max(X,Y)*2+1,2):
    s = 0
    x = X-i//2
    y = Y-i//2
    if x >= 1:
        s += x*A 
    if y >= 1:
        s += y*B
    s += i*C
    ans = min(ans, s)
print(ans)