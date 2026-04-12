r,g,b = input().split()
rgb = int("".join([r, g, b]))
print("YES" if rgb%4==0 else "NO")