n = int(input())
h = [int(i) for i in input().split()]
x = 1
if n == 1:
    print(x)
else:
    if h[1] >= h[0]:
        x += 1

    for i in range(2, n):
            hh = h[0:i]
            if h[i] >= max(hh):
                x += 1
    print(x)