n = int(input())
x = list(map(int, input().split()))
 
xs = list(sorted(x))
b1 = xs[n//2-1]
b2 = xs[n//2]
for xi in x:
    if xi<=b1:print(b2)
    else:print(b1)
