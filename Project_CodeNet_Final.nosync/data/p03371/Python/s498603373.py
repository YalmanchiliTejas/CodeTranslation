A,B,C,X,Y = map(int,input().split())
ans = float('inf')
for c in range(max(X,Y) + 1):
    tmp = c*2*C
    tmp += max(0,X-c)*A
    tmp += max(0,Y-c)*B
    ans = min(ans, tmp)
print(ans)