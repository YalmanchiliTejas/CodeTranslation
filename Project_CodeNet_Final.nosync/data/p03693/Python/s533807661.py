r, g, b = map(int, input().split())

target = 10 * g + b
if target % 4 == 0:
    print("YES")
else:
    print("NO")
