
from collections import defaultdict

N = int(input())
S = []
for i in range(N):
    S.append(input().rstrip())
    

dic = defaultdict(int)
for i in range(len(S[0])):
    dic[S[0][i]] += 1


for s in S[1:]:
    temp_dic = defaultdict(int)
    for i in range(len(s)):
        temp_dic[s[i]] += 1
        
    for k, v in dic.items():
        dic[k] = min(v, temp_dic[k])
        
ans = ""
for k,v in dic.items():
    ans = ans + k*v

ans = sorted(ans)
print("".join(ans))