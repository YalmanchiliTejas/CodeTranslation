r, g, b = map(int, input().split())
num = r * 100 + g * 10 + b
if not(num % 4) :
    print("YES")
else:
    print("NO")