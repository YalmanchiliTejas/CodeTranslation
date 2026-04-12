args = input().split()

r, g, b = args

n = int(r) * 100 + int(g) * 10 + int(b) * 1

if n % 4 == 0:
    print("YES")
else:
    print("NO")
