r, g, b = [int(i) for i in input().split()]
sum = 4*100 + g*10 + b
if sum % 4 == 0:
    print("YES")
else:
    print("NO")
