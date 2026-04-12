r,g,b = [int(x) for x in input().split()]

mul = r*100 + g*10 + b

if mul % 4 == 0:
    print("YES")
else:
    print("NO")