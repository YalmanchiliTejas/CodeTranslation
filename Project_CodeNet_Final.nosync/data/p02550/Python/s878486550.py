def pow_mod(x, y, mod=10**9 + 7):
    if y == 0:
        return 1
    res = 1
    for i in range(y.bit_length()):
        if y & (1 << i):
            res *= x
            res %= mod
        x *= x
        x %= mod
    return res


n, x, m = map(int, input().split())

order = [0] * (m+1)
cnt = [-1] * (m+1)

now = x
a = -1
b = -1
for i in range(n):
    if cnt[now] != -1:
        a = cnt[now]
        b = i
        break
    order[i] = now
    cnt[now] = i
    now = pow_mod(now, 2, m)

if a == -1 and b == -1:
    print(sum(order))
    exit()

ans = 0
roop = [0]
for i in range(b):
    if i < a:
        ans += order[i]
    else:
        roop.append(order[i] + roop[-1])

n -= a

tmp = n % (b-a)
freq = n // (b-a)

ans += roop[-1] * freq
ans += roop[tmp]
print(ans)

