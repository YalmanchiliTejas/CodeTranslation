r, g, b = [int(x) for x in input().split()]
result = 10*g+b

if result % 4 == 0:
    print("YES")
else:
    print("NO")