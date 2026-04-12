# coding: utf-8
A, B, C, X, Y = map(int, input().split())
ans = 0
if A+B < C*2:
    ans += (A+B)*min(X, Y)
else:
    ans += C * 2 * min(X, Y)
if X < Y:
    tmp = B*(Y-X)
else:
    tmp = A*(X-Y)
AB = C*abs(X-Y)*2
print(ans + min(tmp, AB))