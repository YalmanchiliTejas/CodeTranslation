N=int(input())
S=input()
K=int(input())
target=S[K-1]
l=[]
for i in range(N):
    if target!=S[i]:
        l.append("*")
    else:
        l.append(S[i])
s="".join(l)
print(s)