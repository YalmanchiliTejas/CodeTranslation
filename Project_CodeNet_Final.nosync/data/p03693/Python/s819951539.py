r, g, b = input().split()
rgb = r + g + b
rgb = int(rgb)
if rgb % 4 == 0:
    print("YES")
else:
    print("NO")