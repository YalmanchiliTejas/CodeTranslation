n = int(input())
list_s = []
for i in range(n):
    dict_i = {}
    si = str(input())
    for j in range(len(si)):
        try:
            dict_i[si[j]] += 1
        except KeyError:
            dict_i[si[j]] = 1
    list_s.append(dict_i)

set_ans = set(list_s[0].keys())
for dic in list_s:
    set_ans = set_ans & set(dic.keys())
dic_ans = {}
for alp in set_ans:
    dic_ans[alp] = 100

for dic in list_s:
    for key, value in dic.items():
        try:
            if dic_ans[key] > value:
                dic_ans[key] = value
        except KeyError:
            pass
list_ans = []
for key, value in dic_ans.items():
    for i in range(value):
        list_ans.append(key)
list_ans.sort()
if len(list_ans) == 0:
    print("")
else:
    print("".join(list_ans))
