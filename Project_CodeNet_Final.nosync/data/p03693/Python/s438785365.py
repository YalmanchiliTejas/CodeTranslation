r, g, b = map(int, input().split())
s = int(str(g) + str(b))
if s % 4 == 0:
    print("YES")
else:
    print("NO")