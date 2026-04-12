# C問題
n = int(input())
S = []
for i in range(n):
    S.append(input())
base = min(S, key = len)
S.remove(base)
ans = []
for i in range(len(base)):
    flag = True
    for k in range(len(S)):
        if base[i] not in S[k]:
            flag = False
        else:
            place = S[k].find(base[i])
            S[k] = S[k].replace(base[i], '', 1)            
    if flag:
        ans.append(base[i])
ans.sort()
char_ans = ''
for i in range(len(ans)):
    char_ans += ans[i]
print(char_ans)