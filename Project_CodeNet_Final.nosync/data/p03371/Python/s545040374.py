A, B, C, X, Y = map(int, input().split())

ans = 0
if (A + B) / 2 >= C:
    #AB = C
    ans += min(X, Y) * C * 2
    X, Y =X - min(X, Y), Y - min(X, Y)

if A >= 2 * C:
    A = 2 * C
if B >= 2 * C:
    B = 2 * C

while X != 0:
    ans += A
    X -= 1
while Y != 0:
    ans += B
    Y -= 1

print(ans)