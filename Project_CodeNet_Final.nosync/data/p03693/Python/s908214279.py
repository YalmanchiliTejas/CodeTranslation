r, g, b = map(str, input().split())
check = int(g[0] + b[0])
if check % 4 == 0: print("YES")
else: print("NO")