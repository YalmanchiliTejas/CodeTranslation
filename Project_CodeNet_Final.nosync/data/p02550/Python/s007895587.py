n, x, m = map(int,input().split())

amari = [0]*m
v = [x]

cnt = 0
while True:
    xn_1 = x**2%m
    cnt += 1
    if x == 0:
        break
    amari[x] = xn_1
    if amari[xn_1]:
        break
    v.append(xn_1)
    x = xn_1

#print(v)

if 0 in v:
    ans = sum(v)
else:
    ind = v.index(xn_1)
    rooplen = len(v) - ind
    ans = sum(v[0:ind])
    l = n-ind
    if rooplen:
        ans += (l//rooplen)*sum(v[ind:])
        nokori = l - rooplen*(l//rooplen)
        ans += sum(v[ind:ind+nokori])
    
#print(v)
print(ans)