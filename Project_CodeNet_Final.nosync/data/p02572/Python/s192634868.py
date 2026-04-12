mod = int(1e9 + 7)

def pw(b, ex):
    if ex == 0: return 1
    if ex == 1: return b
    if ex & 1: return b % mod * pw((b*b) % mod, ex >> 1) % mod
    return pw((b*b) % mod, ex >> 1) % mod

n = int(input())
x = list(map(int,input().split()))
st = 0
en = 0

for i in x:
    st = (st + i) % mod
    en = (en + (i * i) % mod) % mod
    
st *= st
ans = int((st - en + mod) % mod)
ans = int(ans * int(pw(2, mod - 2)) % mod) % mod
print (int(ans))