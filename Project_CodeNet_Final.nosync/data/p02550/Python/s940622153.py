N, X, M = map(int, input().split())

count = X
bef = X
_sum = [bef]
dic = {}

for i in range(1, N):
    bef = pow(bef, 2, M)
    if bef in dic:
        posi = dic[bef]
        l = len(_sum) - posi
        plus = sum(_sum[posi:])
        count += plus * ((N - i) // l)
        mod = ((N - i) % l)
        count += sum(_sum[posi:posi + mod])
        break
    else:
        dic.setdefault(bef, i)
        _sum.append(bef)
    count += bef

print(count)