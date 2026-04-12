s, t, c, x, y = list(map(int, input().split()))
a = [s, x]
b = [t, y]
if x > y:
    large = a
    least = b
else:
    large = b
    least = a
ans = 0
if s + t >= c * 2:
    ans += c * 2 * least[1]
    if large[0] > c * 2:
        ans += c * 2 * (large[1] - least[1])
    else:
        ans += large[0] * (large[1] - least[1])
else:
    ans += s * x + t * y
print(ans)
