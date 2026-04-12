n,x,m = map(int,input().split())
mod = m
amari = [-1]*m
a = x
cnt = 1
l = 0
r = 0
while 1:
    # print(a)
    if cnt == n:
        break
    
    if amari[a] != -1:
        l = amari[a]
        r = cnt
        # print(a,amari[a])
        break
    else:
        amari[a] = cnt
    cnt += 1
    a = ((a % m)**2) % m
    # if cnt > m:
    #     print("error")
    #     exit()
ans = 0
if cnt == n:
    l = 0
    r = n
# print(l,r)
a = x
temp = 0

for i in range(l-1):
    ans += a
    a = (a**2) % mod
# print(ans)


for i in range(r-l):
    temp += a
    a = (a**2) % mod
ans += temp * ((n-l+1)//(r-l))
# print(ans,a,temp,temp * (n-l)//(r-l),(n-l)//(r-l),temp * ((n-l)//(r-l)))


if r != n:
    for i in range((n-l+1)%(r-l)):
        ans += a
        a = (a**2) % mod
        # print(ans)
if n == 1:
    ans //=2
print(ans)