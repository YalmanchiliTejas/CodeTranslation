import collections
n = int(input())
all_ma = []
for _ in range(n):
    tmp_li = list(input())
    tmp_c = collections.Counter(tmp_li)
    all_ma.append(tmp_c)
base = all_ma[0]
for target in all_ma:
    tmp_dic = {}
    for k,v in base.items():
        if k in target:
            tmp_dic[k] = min(v,target[k])
    base = tmp_dic
if len(base) == 0:
    print('')
else:
    ans_lis = []
    for k,v in base.items():
        ans_lis.append(k*v)
        ans_lis.sort()
    print(''.join(ans_lis))