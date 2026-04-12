n = int(input())
A = list(map(int, input().split()))

#互いに素なa,bについて、a*x+b*y=1の一つの解
def extgcd(a,b):
    r = [1,0,a]
    w = [0,1,b]
    while w[2]!=1:
        q = r[2]//w[2]
        r2 = w
        w2 = [r[0]-q*w[0],r[1]-q*w[1],r[2]-q*w[2]]
        r = r2
        w = w2
    #[x,y]
    return [w[0],w[1]]

# aの逆元(mod m)を求める。(aとmは互いに素であることが前提)
def mod_inv(a,m):
    x = extgcd(a,m)[0]
    return (m+x%m)%m

mod = 10**9 + 7
total = 0
for a in A:
    total += a
    total %= mod

sq = 0
for a in A:
    sq += a**2
    sq %= mod

inv = mod_inv(2, mod)

ans = (total**2 - sq) * inv
ans %= mod
print(ans)