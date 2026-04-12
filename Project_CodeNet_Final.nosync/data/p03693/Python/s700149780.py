r,g,b = map(int, input().split())
if (int(str(r) + str(g) + str(b))) % 4 == 0:
    print("YES")
else:
    print("NO")