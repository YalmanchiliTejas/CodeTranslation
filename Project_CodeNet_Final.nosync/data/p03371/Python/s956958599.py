a, b, c, x, y = map(int, input().split())
resa = a*x + b*y
resb = min(x,y)*c*2 + a*(x-min(x,y)) + b*(y-(min(x,y)))
resc = max(x,y)*2 * c
print (min(resa, resb, resc))