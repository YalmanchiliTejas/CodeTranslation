N = input()
K = int(input())
ng = [0] * (K + 1)
ok = [0] * (K + 1)

ng[0] = 1
ng_count = 0
for n in N:
    n = int(n)
    if n == 0:
        for k in range(K, 0, -1):
            ok[k] = ok[k] + ok[k - 1] * 9
    else:
        ng_count += 1
        for k in range(K, 0, -1):
            ok[k] = ok[k] + ok[k - 1] * 9 + ng[k - 1] * (n - 1) + ng[k]
        ok[0] = 1
        for k in range(K+1):
            ng[k] = int(k == ng_count)

print(ng[-1] + ok[-1])
