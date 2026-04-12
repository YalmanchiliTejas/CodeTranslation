a, b, c, x, y = [int(s) for s in input().split()]
ans = 10 ** 9
for i in range(max(x, y) + 1):
    ans_temp = c * 2 * i + a * max(x - i, 0) + b * max(y - i, 0)
    if ans_temp < ans:
        ans = ans_temp
print(ans)