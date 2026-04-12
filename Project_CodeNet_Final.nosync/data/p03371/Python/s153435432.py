import sys
input = sys.stdin.readline
A, B, C, X, Y = [int(x) for x in input().split()]
ans_notAB = A * X + B * Y
temp = min(X,Y)
ans_AB = 2 * temp * C
if X > Y:
    X -= Y
    ans_AB += min([X * A, 2 * X * C])
elif Y > X:
    Y -= X
    ans_AB += min([Y * B, 2 * Y * C])
print(min(ans_AB,ans_notAB))