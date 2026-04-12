n, x, m = map(int, input().split())



set_ = set([x])
res = [x]
for i in range(m + 200):
    x = x ** 2 % m
    if x in set_:
        break
    res.append(x)
    set_.add(x)

if len(res) >= n:
    print(sum(res[0:n]))
    exit()

init = 0
init_terms = 0
ans = 0
for i in range(len(res)):
    if res[i] == x:
        l = i
        break
    init += res[i]
    init_terms += 1

ans = init
lap = res[l:]
sum_lap = sum(lap)
len_lap = len(lap)



div, mod = divmod(n - init_terms, len_lap)
ans += div * sum_lap + sum(lap[0:mod])
print(ans)