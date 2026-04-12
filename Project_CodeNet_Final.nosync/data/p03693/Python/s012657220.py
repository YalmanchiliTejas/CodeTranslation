a, b, c = map(int, input().split())
s = a * 100 + b * 10 + c
if s % 4 == 0:
    print("YES")
else:
    print("NO")