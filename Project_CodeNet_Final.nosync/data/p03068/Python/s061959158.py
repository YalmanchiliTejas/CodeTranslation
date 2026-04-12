b = int(input())
a = list(input())
n = int(input())

control = a[n - 1]

for i in range(0, b):
    if a[i] != control:
        a[i] = "*"
    print(a[i], end = "")