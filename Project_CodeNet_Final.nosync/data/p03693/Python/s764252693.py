r, g, b = map(int, input().split())
r = r*100
g = g*10
i = r + g + b
if i%4 == 0 :
    print("YES")
else :
    print("NO")