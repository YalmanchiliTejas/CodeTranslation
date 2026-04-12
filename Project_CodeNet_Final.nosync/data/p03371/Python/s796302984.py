A, B, C, X, Y = [int(i) for i in input().split()]

ans1 = 0
ans2 = 0
if (A+B) <= 2*C:
    print(A*X + B*Y)
else:
    ans1 = A*(X-min(X, Y)) + B*(Y-min(X, Y)) + 2*C*min(X, Y)
    ans2 = 2*C*max(X, Y)
    print(min(ans1, ans2))
