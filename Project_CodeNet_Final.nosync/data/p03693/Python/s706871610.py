r, g, b = map(str, input().split())
sum = r + g + b
if int(sum) % 4 == 0:
    print("YES")
else:
    print("NO")