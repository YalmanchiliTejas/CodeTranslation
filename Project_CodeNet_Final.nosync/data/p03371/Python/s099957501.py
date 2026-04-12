a, b, c, x, y = map(int, input().split())

ab = c * 2

if ab < a and ab < b:
    print(max(x, y) * ab)
else:
    answer = min(a+b, ab) * min(x, y)

    if x > y:
        answer += min(a, ab) * (x - y)
    else:
        answer += min(b, ab) * (y - x)
    print(answer)