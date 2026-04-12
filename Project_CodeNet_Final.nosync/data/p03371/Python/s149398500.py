A, B, C, X, Y = list(map(int,input().split()))
ans = float('Inf')
for i in range(max(X,Y)*2+1):
    tmp = i * C
    if i / 2 < X:
        tmp += A*(X-i//2)
    if i / 2 < Y:
        tmp += B*(Y-i//2)
    ans = min(ans,tmp)
print(ans)