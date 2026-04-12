n=int(input())
s=[input() for i in range(n)]
alphabets=[chr(i) for i in range(97,123)]
ans=[10**10]*26

for i in range(26):
    for j in s:
        p=j.count(alphabets[i])
        ans[i]=min(ans[i],p)
        
moji=""
for i in range(26):
    moji+=alphabets[i]*ans[i]
print(moji)
    