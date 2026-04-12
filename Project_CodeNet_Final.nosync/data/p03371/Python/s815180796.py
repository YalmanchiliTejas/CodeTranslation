ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

a, b, c, x, y = mi()
n_min = min(x,y)
price = 0
if(a+b > 2*c):
    price += 2*c * n_min
else:
    price += (a+b) * n_min

if(x>y):
    n_mod = x-n_min
    d = a
else:
    n_mod = y-n_min
    d = b

if(d < c*2):
    price += d * n_mod
else:
    price += c*2 * n_mod

print(price)