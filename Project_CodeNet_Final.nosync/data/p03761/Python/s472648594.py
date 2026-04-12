N = int(input())
S = [input() for _ in range(N)]
li = [[0 for _ in range(26)]for _ in range(N)]
cand = [10**6]*26
ans = ''
for ind,i in enumerate(S):
    for x in i:
        li[ind][ord(x)-97]+=1
    for li_ind,j in enumerate(li[ind]):
        cand[li_ind] = min(j,cand[li_ind])

for ind,i in enumerate(cand):
    ans += chr(97+ind)*i
print(ans)
