N=int(input())
S=input()
K=int(input())
tmp=S[K-1]
out=[]
for i in range(N):
    if S[i]!=tmp:
        out.append("*")
    else:
        out.append(S[i])
ttt=""
for i in out:
    ttt="{}{}".format(ttt,i)
print(ttt)
