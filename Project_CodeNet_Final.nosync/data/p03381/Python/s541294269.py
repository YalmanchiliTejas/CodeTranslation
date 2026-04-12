n = int(input())
x = list(map(int, input().split()))
xs = sorted(x)
mid_n = n//2
lx = xs[mid_n-1]
hx = xs[mid_n]
for i in range(n):
    print(hx) if x[i] < hx else print(lx)