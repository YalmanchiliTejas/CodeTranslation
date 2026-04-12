r, g, b = map(int, input().split())
c = r*100 + g*10 + b
if c%4 == 0:
    print("YES")
else:
    print("NO")