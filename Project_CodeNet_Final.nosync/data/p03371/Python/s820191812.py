import sys
input = sys.stdin.readline

A, B, C, X, Y = map(int, input().split(' '))
set_price = min(A+B, C*2)
set_num = min(X, Y)

ans = set_price * set_num
if X > Y:
    ans += min(A, C*2) * (X-Y)
elif X < Y:
    ans += min(B, C*2) * (Y-X)
print(ans)