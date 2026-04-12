n = int(input())
a = list(map(int,input().split()))
mod = 10**9+7
s = sum(a)
# for i in a:
#     s  = s*a % mod
ans = 0
for i in a:
    ans = (ans + (s-i)*i) % mod
print(ans*pow(2,mod-2,mod) % mod)