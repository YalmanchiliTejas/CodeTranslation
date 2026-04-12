r,g,b = [int(x) for x in input().split()]

if (r*100+g*10+b) % 4 == 0:
    print("YES")
else:
    print("NO")