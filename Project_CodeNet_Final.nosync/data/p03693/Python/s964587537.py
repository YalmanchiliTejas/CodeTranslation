r, g, b = map(int, input().split())

sum = 0
sum += r * 100 + g * 10 + b

if sum % 4 == 0:
    print("YES")
else:
    print("NO")
