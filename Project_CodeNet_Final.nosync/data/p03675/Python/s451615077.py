n = int(input())
a = list(map(int, input().split()))

b = []
if n % 2 == 0:
    for i in reversed(range(1, n, 2)):
        b.append(str(a[i]))
    for i in range(0, n, 2):
        b.append(str(a[i]))
else:
    for i in reversed(range(0, n + 1, 2)):
        b.append(str(a[i]))
    for i in range(1, n, 2):
        b.append(str(a[i]))

ans = ' '.join(b)
print(ans)