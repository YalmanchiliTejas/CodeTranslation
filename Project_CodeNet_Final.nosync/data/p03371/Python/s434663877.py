a, b, c, x, y = map(int, input().split())
ans = max(0, x)*a + max(0, y)*b # ABピザを一枚も買わなかった時
for i in range(100001):
    tmp = i*2*c + max(0, x-i)*a + max(0, y-i)*b
    if ans > tmp:
        ans = tmp
print(ans)
