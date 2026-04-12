N=int(input())
S=[sorted(list(input())) for _ in range(N)]
l=S[0]
len_s=len(S)
for i in range(len_s):
    l=list(set(l)&set(S[i]))
ans=''
len_l=len(l)
for i in range(len_l):
    cnt=50
    for j in range(len_s):
        if cnt>S[j].count(l[i]):
            cnt=S[j].count(l[i])
    ans+=(l[i]*cnt)
print(''.join(sorted(ans)))