from collections import Counter
N = int(input())
S=[]

for n in range(N):
    S.append(Counter(list(input())))

S_=dict(S[0])
for s in S:
    if len(S_) > len(s):
        S_=dict(s)

for s in S:
    for s_ in S_.keys():
        S_[s_]=min(s[s_],S_[s_])

S_key=list(S_.keys())
S_key.sort()

ans=''
for k in S_key:
    ans += k*S_[k]
print(ans)
