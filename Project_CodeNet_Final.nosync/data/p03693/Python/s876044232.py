r,g,b = input().split()
r = int(r)
g = int(g)
b = int(b)

number = r * 100 + g * 10 + b

if number % 4 == 0:
    print("YES")
else:
    print("NO")