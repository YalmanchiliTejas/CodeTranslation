r, g, b = map(int, input().split())
value = r*100 + g * 10 + b
if value % 4 == 0:
    print("YES")
else:
    print("NO")
