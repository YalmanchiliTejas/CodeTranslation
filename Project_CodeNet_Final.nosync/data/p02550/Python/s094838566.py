N, X, M = map(int, input().split())

lim = 10**5*2+1

f = [0]*(lim)
a = [0]*(lim)

x = X
f[x] = 1
a[1] = x

ans = x

i = 1
l = N
while i < l:
    i += 1

    x **= 2
    x %= M
    if not x:
        break

    if f[x]:
        lp_len = (i-f[x])
        z = (l-i+1)//lp_len
        if z:
            ls = ans - a[f[x]-1]
            ans += ls * z
            i += z*lp_len

    if i <= l:
        ans += x
    
    f[x] = i
    if i < lim:
        a[i] = ans

print(ans)