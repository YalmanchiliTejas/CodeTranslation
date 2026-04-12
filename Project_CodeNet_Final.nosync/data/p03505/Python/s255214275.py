k, a, b = map(int, input().split())
if a >= k:
    print(1)
elif a <= b:
    print(-1)
else:
    print(((k - a - 1) // (a - b) + 1 ) * 2 + 1)
