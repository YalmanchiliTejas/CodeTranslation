r, g, b = map(int , input().split())

rgb = 100*r + 10*g + b

if (rgb % 4 == 0):
    print("YES")
else:
    print("NO")