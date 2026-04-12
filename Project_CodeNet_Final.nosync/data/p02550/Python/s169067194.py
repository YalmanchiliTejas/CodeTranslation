N, X, M = [int(x) for x in input().split()]
s = [0] * (M+10)
s[1] = X
d = {X: 0}
tmp = X
for i in range(M):
    tmp = tmp * tmp % M
    if tmp == 0:
        print(s[i+1])
        exit()
    elif tmp in d:
        l, r = d[tmp], i+1
        sl = s[r] - s[l]
        loop = r-l
        ans = sl*((N-l)//loop) + s[l+(N-l)%loop]
        print(ans)
        exit()
    else:
        d[tmp] = i+1
        s[i+2] = s[i+1] + tmp
print(d)
