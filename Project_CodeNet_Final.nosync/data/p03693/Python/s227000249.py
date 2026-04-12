r,g,b=[int(i) for i in input().split()]

n = g*10 + b
if n % 4 == 0:
    print("YES")
else:
    print("NO")