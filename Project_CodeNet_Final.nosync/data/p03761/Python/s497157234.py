N = int(input())
L = [list(input()) for _ in range(N)]

dic = {}

for l in L[0]:
    if l in dic:
        dic[l] += 1
    else:
        dic[l] = 1
        
for i in range(N):
    tmp = {}
    for j in range(len(L[i])):
        if L[i][j] in tmp:
            tmp[L[i][j]] += 1
        else:
            tmp[L[i][j]] = 1
            
    for t in dic:
        if t in tmp:
            dic[t] = min(dic[t], tmp[t])
        else:
            dic[t] = 0
     
res_list = []
for d in dic:
    for i in range(dic[d]):
        res_list.append(d)
  
res_list.sort()
result = ''
for res in res_list:
    result += res

print(result)