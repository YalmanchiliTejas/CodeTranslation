r, g, b = input().split()

rgb = 100 * int(r) + 10 * int(g) + int(b)

if rgb % 4 == 0:
    print("YES")

else:
    print("NO")