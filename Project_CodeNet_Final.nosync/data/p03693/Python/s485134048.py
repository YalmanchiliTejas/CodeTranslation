r, b, g = map(int, input().split())

rgb = r * 100 + b * 10 + g
if rgb % 4 == 0:
    print("YES")
else:
    print("NO")
