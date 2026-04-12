A, B, C, X, Y = map(int, input().split())
ans0 = A * X + B * Y
# A
ans1 = A * X + 2 * C * Y
# B
ans2 = 2 * C * X + B * Y
# C
ans3 = 2 * C * max(X, Y)
# D
#
t = abs(X - Y)

ans4 = 2 * C * min(X, Y)
ans5 = 10 ** 18
ans6 = 10 ** 18
if X > Y:
    temp1 = A * t
    temp2 = 2 * C * t
    ans5 = ans4 + min(temp1, temp2)
else:
    temp1 = B * t
    temp2 = 2 * C * t
    ans6 = ans4 + min(temp1, temp2)

print(min(ans0,ans1, ans2, ans3, ans5, ans6))
