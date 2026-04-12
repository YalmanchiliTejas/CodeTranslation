N=int(input())
cnt=[0,]*26
base=input()
for i in range(len(base)):
    cnt[ord(base[i])-97]+=1
for i in range(N-1):
    cnt2=[0,]*26
    cmp=input()
    for i in range(len(cmp)):
        cnt2[ord(cmp[i])-97]+=1
    for i in range(26):
        if cnt[i] > cnt2[i]:
            cnt[i]=cnt2[i]
ans=""
for i in range(26):
    for j in range(cnt[i]):
        ans+=chr(i+97)
print(ans)