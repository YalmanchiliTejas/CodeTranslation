N = int(input())
K = str(input())
S = int(input())
ans = ''
kw = K[S-1]
for i in K:
    if i != kw:
        i = '*'
    else:
        pass
    ans += i
print(ans)