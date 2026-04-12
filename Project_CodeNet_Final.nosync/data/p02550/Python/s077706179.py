n , x , m = map(int,input().split())
amari = [-1 for i in range(m)]
amari[x] = 0
cou = 0
now = x
p = 0
zyun = [x]
while True:
    nex = (now**2) % m
    if nex == 0:
        p = 1
        break
    elif amari[nex] == -1:
        amari[nex] = amari[now] + 1
        now = nex
        zyun.append(nex)
    elif amari[nex] != -1:
        p = 2
        break

if p == 1:
    ans = 0
    for i in range(m):
        if amari[i] != -1:
            ans += i
    print(ans)
elif p == 2:
    ans = 0
    ans += sum(zyun[:amari[nex]])
    ans += sum(zyun[amari[nex]:]) * ((n-amari[nex])//(amari[now]-amari[nex]+1))
    y = (n-amari[nex]) % (amari[now]-amari[nex]+1)
    if y != 0:
        ans += sum(zyun[amari[nex]:amari[nex]+y])
    print(ans)