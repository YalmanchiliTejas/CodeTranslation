a, b, c = map(int, input().split())
v = 100 * a + 10 * b + c
if v % 4 == 0:
    print("YES")
else:
    print("NO")
