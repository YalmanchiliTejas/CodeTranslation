rgb = input().split()
r = int(rgb[0])
g = rgb[1]
b = rgb[2]
if int(g+b) % 4 == 0:
    print("YES")
else:
    print("NO")