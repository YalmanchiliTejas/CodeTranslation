a, b, c, x, y = map(int, input().split())
d = []
for num_c in range(max(x, y)+1):
    money = num_c * 2 * c + max(x-num_c, 0) * a + max(y-num_c, 0) * b
    d.append(money)
print(min(d))