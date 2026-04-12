n=int(input())
cnt=[10000]*26
for i in range(n):
    tmp=[0]*26
    S=input()
    for j in range(len(S)):
        tmp[ord(S[j])-97]+=1
    for j in range(26):
        cnt[j]=min(tmp[j],cnt[j])
li=[]
for i in range(26):
    for j in range(cnt[i]):
        li.append(chr(i+97))
print(''.join(li))