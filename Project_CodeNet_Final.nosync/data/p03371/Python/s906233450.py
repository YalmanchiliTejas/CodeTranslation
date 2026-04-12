A, B, C, X, Y = map(int, input().split())
"""
Cを2k枚買う
"""

ans = 10 ** 10
k = 0
while True:
    money = C * k
    money += A * max(0, X - k // 2) + B * max(0, Y - k // 2)
    # print(max(0, X - k // 2), max(0, Y - k // 2), k, money)
    ans = min(ans, money)
    if k // 2 >= max(X, Y):
        break
    k += 2
print(ans)
