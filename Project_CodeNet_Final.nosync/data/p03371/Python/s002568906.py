A, B, C, X, Y = list(map(int, input().split()))

if X>Y:
    A, B = B, A
    X, Y = Y, X
excessB = Y-X

ans = min(2*C, A+B)*X
ans += min(2*C, B)*excessB

print(ans)
