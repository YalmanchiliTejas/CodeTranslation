r,g,b = map(int, input().split())

num = 10*g + b
if num == 0:
    print("TES")
elif num % 4 == 0:
    print("YES")
else:
    print("NO")