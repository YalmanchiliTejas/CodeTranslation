n = int(input())
ans_re = []
ans = ""
dic = {}
dic_re = {}

for i in range(n):
    S = list(input())
    for x in S:
        if x not in dic_re:
            dic_re[x] = 1
        else:
            dic_re[x] += 1
    
    if i == 0:
        dic = dic_re.copy()
    else:
        for x in dic:
            if x in dic_re:
                a = dic[x]
                b = dic_re[x]
                dic[x] = min(a, b)
            else:
                dic[x] = 0
    dic_re.clear()

for x in dic:
    ans_re.append([x, dic[x]])
ans_re.sort()
l = len(ans_re)
for i in range(l):
    ans = ans + ans_re[i][0]*ans_re[i][1]
print(ans)