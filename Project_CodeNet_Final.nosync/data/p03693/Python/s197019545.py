r, g, b = [ int(i) for i in input().split()]
if (r*100+g*10+b)%4:
    print("NO")
else:
    print("YES")
