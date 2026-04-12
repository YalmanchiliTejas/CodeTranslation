r,g,b = map(int, input().split())
if (g*2+b)%4 == 0:
    print("YES")
else:
    print("NO")