a, b, c = map(int, input().split())
s = a * 100 + b * 10 + c
r = "YES" if s % 4 == 0 else "NO"
print(r)
