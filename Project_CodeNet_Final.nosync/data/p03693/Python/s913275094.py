r, g, b = map(int, input().split())

sum = 100 * r + 10 * g + b

if sum % 4 == 0:
    print("YES")

else:
    print("NO")
