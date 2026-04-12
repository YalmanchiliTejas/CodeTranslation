RGB = list(map(str, input().split()))
rgb = "".join(RGB)
if (int(rgb) % 4) == 0:
    print("YES")
else:
    print("NO")
