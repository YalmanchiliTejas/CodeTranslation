r, g, b = input().split()
sp = r + g + b
if int(sp) % 4 == 0:
    print("YES")
else:
    print("NO")