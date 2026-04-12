n=int(input())
s=[input() for _ in [0]*n]
l=list(map(chr,range(97,123)))

for i in range(26):
    t=min(s[j].count(l[i]) for j in range(n))
    print(l[i]*t,end='')