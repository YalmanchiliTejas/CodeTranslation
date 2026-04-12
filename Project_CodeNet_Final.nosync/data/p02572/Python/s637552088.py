#abcdef
#a*b,a*c,a*d,a*e,a*f
#b*c,b*d,b*e,b*f
#c*d,c*e,c*f
#d*e,d*f
#e*f

n = int(input())
l = list(map(int,input().split()))

mod = 10**9 + 7
all_l = 0
for i in range(n):
    all_l += l[i]
    all_l %= mod

ans = 0
for i in range(n-1):
    all_l = (all_l-l[i])%mod
    ans += (l[i]*all_l)%mod
    ans %= mod

print(ans)
