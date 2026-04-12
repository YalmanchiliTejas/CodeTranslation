a, b, c, x, y = (int(i) for i in input().split())

tmp1,tmp2,tmp3 = 0,0,0

if x > y:
    tmp1 = y*2*c+(x-y)*a
    tmp3 = x*2*c
else:
    tmp1 = x*2*c+(y-x)*b
    tmp3 = y*2*c

tmp2 = a*x+b*y

print(min(tmp1,tmp2,tmp3))
