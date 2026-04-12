from collections import Counter
n=int(input())
S=[input() for i in range(n)]

nes=set(S[0])
for i in range(1,n):
    nes=nes&set(S[i])
nes=list(nes)

words={}
for i in range(n):
    for chr,cnt in Counter(S[i]).items():
        if chr in nes:
            if chr not in words:words[chr]=cnt
            else:words[chr]=min(words[chr],cnt)

ans=""
for i,j in sorted(words.items()):
    ans +=i*j
print(ans)