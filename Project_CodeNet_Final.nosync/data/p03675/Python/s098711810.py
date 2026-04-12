n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(0, n, 2):
    b.append(a[i])
b = list(reversed(b))
for i in range(1, n, 2):
    b.append(a[i])
if n % 2 == 0:
    b = list(reversed(b))
print(' '.join(list(map(str, b))))