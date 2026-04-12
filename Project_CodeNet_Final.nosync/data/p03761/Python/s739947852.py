N = int(input())
al=[chr(ord('a') + i) for i in range(26)]
out = [1000]*26
for i in range(N):
    S = list(input())
    LS = len(S)
    tmp = [0]*26
    for j in range(LS):
        tmp[ord(S[j])-ord("a")]+=1
    for j in range(26):
        out[j]=min(out[j],tmp[j])
S = ""
for i in range(26):
    S += out[i]*chr(ord("a")+i)
print(S)
