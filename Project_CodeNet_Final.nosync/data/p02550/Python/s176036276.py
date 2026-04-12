def f(a):
    return a * a % m


n, x, m = map(int, input().split())

a = x
i = 1
li = [a]
num2index = {a: 1}
while f(a) not in num2index and i + 1 <= n:
    i += 1
    a = f(a)
    li.append(a)
    num2index[a] = i

if i == n:
    ans = sum(li)
else:
    before_loop = num2index[f(a)]
    loop, left = divmod(n - i, i - before_loop + 1)
    loop_sm = loop * sum(li[before_loop-1:])
    left_sm = sum(li[before_loop-1:before_loop-1+left])
    ans = sum(li) + loop_sm + left_sm

print(ans)
