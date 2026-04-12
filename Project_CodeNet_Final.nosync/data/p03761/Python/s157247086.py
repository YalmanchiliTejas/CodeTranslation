import collections
n = int(input())

dic = collections.defaultdict(int)
dic_tmp = collections.defaultdict(int)
for i in range(n):
    s = input()
    if i == 0:
        for j in range(len(s)):
            dic[s[j]] += 1
    else:
        for j in range(len(s)):
            dic_tmp[s[j]] += 1
        for j in dic.keys():
            dic[j] = min(dic[j],dic_tmp[j])
    dic_tmp.clear()

ls = list(dic.keys())
ls.sort()
ans = ""
for i in range(len(ls)):
    ans +=  ls[i] * dic[ls[i]]
print(ans)
