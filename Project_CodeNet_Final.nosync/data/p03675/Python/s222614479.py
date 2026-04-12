n = int(raw_input())
a = [int(_) for _ in raw_input().split()]

i = n - 1
while i >= 0:
    print a[i],
    i -= 2
if i == -1:
    i = 0
else:
    i = 1
while i < n - 2:
    print a[i],
    i += 2
if n != 1:
    print a[n - 2]
