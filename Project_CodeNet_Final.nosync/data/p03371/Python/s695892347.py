from math import ceil
a, b, c, x, y = map(int, input().split())

def foo(z):
    res = a*max(x-z//2, 0) + b*max(y-z//2, 0) + c*z
    #print (z, res)
    return res
candid = []
for z in range(max(x, y)*2+1):
    candid.append(foo(z))
print (min(candid))