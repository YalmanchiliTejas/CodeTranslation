h,w = map(int,input().split())
masu = [input() for i in range(h)]
masu = [i for i in masu if i != "."*w]
Tmasu =[]
for j in range(w):
    x = [s[j] for s in masu]
    Tmasu.append("".join(x))
Tmasu = [i for i in Tmasu if i != "."*len(masu)]
ans = []
for k in range(len(masu)):
    x = [s[k] for s in Tmasu]
    ans.append("".join(x))
for l in ans:
    print(l)