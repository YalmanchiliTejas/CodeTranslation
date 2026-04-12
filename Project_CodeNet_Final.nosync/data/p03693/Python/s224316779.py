a, b, c = list(map(int, input().split()))
a = a * 100 + b * 10 + c
if (a % 4 == 0):
    print("YES")
else:
    print("NO")
