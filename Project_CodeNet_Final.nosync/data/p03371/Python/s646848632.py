A, B, C, X, Y = map(int, input().split())
ans = []
ans.append(A * X + B * Y)
tmp = min(X, Y) * C * 2
if X > Y:
    tmp += abs(X - Y) * A
elif X < Y:
    tmp += abs(X - Y) * B
ans.append(tmp)
ans.append(max(X, Y) * C * 2)
print(min(ans))