N=int(input())
S=input()
K=int(input())
c=S[K-1]
s=""
for i in range(N):
    if S[i]!=c:
        s="".join((s,"*"))
    else:
        s = "".join((s, S[i]))
print(s)
