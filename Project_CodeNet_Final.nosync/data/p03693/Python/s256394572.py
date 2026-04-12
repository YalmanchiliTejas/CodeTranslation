r, g, b = map(int, input().split())
n = g*10 + b

if n%4==0:
    print("YES")
else:
    print("NO")