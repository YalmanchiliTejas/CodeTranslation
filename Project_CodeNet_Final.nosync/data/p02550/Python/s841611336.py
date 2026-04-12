n, x, m = map(int, input().split())

tmp = [x]
while x**2%m not in tmp:
    x = x**2%m
    tmp.append(x)

cnt = len(tmp)
x = x**2%m

if n <= cnt:
    print(sum(tmp[:n]))
    exit()

for i in range(len(tmp)):
    if tmp[i] == x:
        st = sum(tmp[:i])
        rp = tmp[i:]
        div, mod = divmod(n-i, len(rp))
        en = sum(rp[:mod])
        print(st+sum(rp)*div+en)
        exit()