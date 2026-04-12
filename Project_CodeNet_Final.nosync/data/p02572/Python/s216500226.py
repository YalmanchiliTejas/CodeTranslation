MOD = 10**9 + 7


def mpow(a,b):
    ans = 1
    while (b> 0):
        if b&1:
            ans = (ans*a)%MOD
        a= (a*a)%MOD
        b= b>>1
    
    return ans


n = int(input())
arr =[int(c) for c in input().split()]
s = sum(arr)

ans = 0
for i in arr:
    su = s-i
    ans = (ans + ((su)*i)%MOD)%MOD

ans = ans * mpow(2,MOD-2)
if ans < 0:
    ans+=MOD

print(ans%MOD)