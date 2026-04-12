x, y, z = map(int, input().split())
a = 100*x + 10* y + z
if a%4 == 0:
    print("YES")
else:
    print("NO")