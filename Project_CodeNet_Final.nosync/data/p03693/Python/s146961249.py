R, G, B = [int(_) for _ in input().split()]

x = R * 100 + G * 10 + B

if x % 4 == 0:
    print("YES")
else:
    print("NO")