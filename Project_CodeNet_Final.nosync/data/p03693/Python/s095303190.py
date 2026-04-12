r,g,b=input().split()

cards = int(r + g + b)

if cards % 4 == 0:
    print("YES")

else:
    print("NO")