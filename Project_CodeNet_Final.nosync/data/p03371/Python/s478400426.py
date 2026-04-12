a,b,c,x,y = [int(x) for x in input().split()]

#そのまま
aprice = a*x + b*y
#組み合わせ
if x > y:
    amari = a*(x-y)
elif x < y:
    amari = b*(y-x)
else:
    amari = 0
bprice = min(x,y)*c*2 + amari
#セットのみ
cprice = c*max(x, y)*2

#print(aprice,bprice,cprice)
print(min(aprice,bprice,cprice))