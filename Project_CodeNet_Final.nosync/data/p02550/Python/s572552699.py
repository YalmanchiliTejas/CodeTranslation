from collections import Counter
n, x, m = map(int, input().split())
appear = [False] * m
r = [x]
appear[x] = True
a = x
i = 1
while True:
    a = (a * a) % m
    if appear[a]:
        if a == 0:
            print(sum(r))
            exit()
        # print(a)
        break
    else:
        appear[a] = True
        r.append(a)
        # if a == 10000:
        #     print(i, a)
        i += 1
        if i == n:
            print(sum(r))
            exit()
cycle_start_i = r.index(a)
cycle_len = len(r) - cycle_start_i
cycle_sum = sum(r[cycle_start_i:])
# print(r[:4]) [10, 100, 10000, 41000]
# print('aa,', cycle_start_i)
# print(cycle_len)
# print(r)
c = Counter(r)
# ans = sum(r) * (n // cycle_len) + sum(r[:(n % cycle_len)])
ans = sum(r[:cycle_start_i]) + cycle_sum * ((n - cycle_start_i) // cycle_len) + sum(r[:((n - cycle_start_i) % cycle_len)])
ans = sum(r[:cycle_start_i]) + cycle_sum * ((n - cycle_start_i) // cycle_len) + sum(r[cycle_start_i:cycle_start_i + ((n - cycle_start_i) % cycle_len)])
print(ans)
