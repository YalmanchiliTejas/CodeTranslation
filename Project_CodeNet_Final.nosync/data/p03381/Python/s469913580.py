n = int(input())
x = list(map(int, input().split()))
xs = sorted(x)
a = xs[n // 2 - 1]
b = xs[n // 2]
for i in x:
    if i <= a:
        print(b)
    else:
        print(a)