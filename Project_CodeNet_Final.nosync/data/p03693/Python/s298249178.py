r, b, g = input().split()
num = int(r + b + g)
if num % 4 == 0:
    print("YES")
else:
    print("NO")