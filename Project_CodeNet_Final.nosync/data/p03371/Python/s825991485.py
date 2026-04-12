A, B, C, X, Y = map(int, input().split())

if X > Y:
    v = A
else:
    v = B

ans = min(A*X+B*Y, C*max(X, Y)*2, C*min(X,Y)*2+(max(X,Y)-min(X,Y))*v)

print(ans)