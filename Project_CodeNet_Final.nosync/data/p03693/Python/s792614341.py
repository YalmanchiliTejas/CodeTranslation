r, g, b = list(map(int, input().split()))

if 1 <= r <= 9 and 1 <= g <= 9 and 1 <= b <= 9:
    res = "YES" if (r * 100 + 10 * g + b) % 4 == 0 else "NO"
    print(res)
else:
    print("error")