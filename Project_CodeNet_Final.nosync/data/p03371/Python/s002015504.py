A, B, C, X, Y = map(int, input().split())
ans = A*X+B*Y
for i in range(1, max(X, Y)+1):
    if i <= min(X, Y):
        ans = min(ans, ans+2*C-(A+B))
    else:
        if X > Y:
            ans = min(ans, ans-A+2*C)
        else:
            ans = min(ans, ans-B+2*C)
print(ans)
