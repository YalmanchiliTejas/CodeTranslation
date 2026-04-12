from collections import Counter

n = int(input())

s = sorted(input())
ans = Counter(s)
for i in range(n-1):
    s = sorted(input())
    c = Counter(s)
    tmp_dic = {}
    for k,v in ans.items():
        if k in c:
            tmp_dic[k] = min(c[k],v)
    ans = tmp_dic

a = ""
ans_list = sorted(ans.items()) 
for i in ans_list:
    a += i[0]*i[1]
print(a)




