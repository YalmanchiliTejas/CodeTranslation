n=int(input())
alfa=[chr(i) for i in range(97, 97+26)]
words={}
for alf in alfa:
    words[alf]=0
for n_ in range(n):
    S=input()
    if n_==0:
        for s in S:
            words[s] = S.count(s)
    else:
        for k,v in words.items():
            words[k]=min(v,S.count(k))
answer=''
for key,value in words.items():
    answer+=key*value
print(answer)
