r,g,b = input().split()
figure = r + g + b
if int(figure) % 4 == 0:
    print("YES")
else:
    print("NO")
