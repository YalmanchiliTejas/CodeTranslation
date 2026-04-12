r, g, b = input().split()
rgb = int(r + g + b)
result = rgb % 4

if result == 0:
    print("YES")
else :
    print("NO")