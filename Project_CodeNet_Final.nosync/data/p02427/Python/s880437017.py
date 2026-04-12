n = int(input())
ans = []
for i in range(1<<n):
    ret = []
    ret.append('%d:' % i)
    for j in range(n):
        if i >> j & 1:
            ret.append(j)
    ans.append(' '.join(map(str, ret)))
print('\n'.join(ans))

