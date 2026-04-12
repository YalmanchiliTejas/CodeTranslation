n=int(input())
a=[list(input()) for i in range(n)]
alpha=[0]*26
for aa in a:
    for x in range(26):
        if chr(ord("a")+x) in aa:
            alpha[x]+=1
ans=""
for x,i in enumerate(alpha):
    if i==n:
        mini=51
        for aa in a:
            cnt=aa.count(chr(ord("a")+x))
            mini=min(mini,cnt)
        ans+=(chr(ord("a")+x))*mini
print(ans)