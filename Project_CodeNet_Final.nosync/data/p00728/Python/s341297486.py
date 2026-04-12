i = int(input())
p = 0
while i != 0:
    k =[ [0]*100]*20
    ma = 0
    mi = 1000
    for pp in range(i):
        l = int(input())
        k[p][pp] = l
        ma = max(ma,l)
        mi = min(mi,l)
    su = sum(k[p]) - ma - mi
    l = i -2
    print(su // l)
    p += 1
    i = int(input()) 
