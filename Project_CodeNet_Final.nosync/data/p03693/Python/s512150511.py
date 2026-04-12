r, g, b = map(int, input().split())
m = 10*g + b
if m % 4 == 0:
    print("YES")
else:
    print("NO")