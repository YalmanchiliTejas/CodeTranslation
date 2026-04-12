r,g,b = map(int,input().split())

number = r * 100 + g * 10 + b

if number % 4 == 0:
    print("YES")
else:
    print("NO")