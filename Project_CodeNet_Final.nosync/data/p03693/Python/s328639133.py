r,g,b = map(str, input().split())
rgb = int(r+g+b)
if rgb % 4:
    print("NO")
else:
    print("YES")