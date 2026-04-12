a,b,c,x,y = map(int,input().split())
res = 9999999999999
for i in range(0, 200002, 2):
    na = x - i//2
    nb = y - i//2
    na = 0 if na < 0 else na
    nb = 0 if nb < 0 else nb
    res = min(res, c * i + a*na + b*nb)
print(res)