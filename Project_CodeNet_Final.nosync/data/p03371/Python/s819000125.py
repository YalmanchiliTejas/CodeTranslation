A, B, C, X, Y = map(int, input().split())
c = C / 2
money = 0
if X > Y:
    m = X
    M = A
    f = Y
    F = B
else:
    m = Y
    M = B
    f = X
    F = A

if A + B > 2 * C:
    money = C * f * 2
    m = m - f
    f = 0

if F > 2 * C: money += f * 2 * C
else: money += f * F

if M > 2 * C: money += m * 2 * C
else: money += m * M

print(money)