dic = {}
n = int(input())
S = [input() for _ in range(n)]

for t in S[0]:
    for tt in t:
        if tt in dic:
            dic[tt] += 1
        else:
            dic[tt] = 1
    
for s in S[1:]:
    temp = {}
    for ss  in s:
        if ss in temp:
            temp[ss] += 1
        else:
            temp[ss] = 1
    for d in dic:
        if d in temp:
            dic[d] = min(dic[d],temp[d])
        else:
            dic[d] = 0
ans = []
for k,n in zip(dic.keys(),dic.values()):
    for j in range(n):
        ans.append(k)
ans.sort()
print("".join(ans))