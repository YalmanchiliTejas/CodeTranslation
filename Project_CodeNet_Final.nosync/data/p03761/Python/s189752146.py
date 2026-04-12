n=int(input())
abc_li=[0]*26
S=input()
for i in range(len(S)):
    abc_li[ord(S[i])-97]+=1

for i in range(n-1):
    S=input()
    tmp_abc_li=[0]*26
    for j in range(len(S)):
        tmp_abc_li[ord(S[j])-97]+=1
    for k in range(26):
        abc_li[k]=min(abc_li[k],tmp_abc_li[k])

ans=''
for i in range(26):
    if abc_li[i]>0:
        ans=ans+(chr(i+97)*abc_li[i])
print(ans)