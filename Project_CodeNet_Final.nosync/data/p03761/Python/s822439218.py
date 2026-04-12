N = int(input())

dic = {}
for c in input():
    if c in dic.keys():
        dic[c] += 1
    else:
        dic[c] = 1

for i in range(N-1):
    tmp_dic = {}
    for c in input():
        if c in tmp_dic.keys():
            tmp_dic[c] += 1
        else:
            tmp_dic[c] = 1
    for k in dic.keys():
        if k in tmp_dic.keys():
            dic[k] = min(dic[k], tmp_dic[k])
        else:
            dic[k] = 0
    
print("".join(sorted([k * dic[k] for k in dic.keys()])))
