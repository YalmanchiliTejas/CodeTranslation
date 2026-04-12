a, b, c = map(int, input().split())

ans = a * 100 + b * 10 + c

if ans % 4 == 0:
    print("YES")
else:
    print("NO")