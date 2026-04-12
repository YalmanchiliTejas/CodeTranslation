N=int(input())
S=input()
K=int(input())-1
k=S[K]
h=[]
for i in range(N):
    g=S[i]
    if k==g:
        h.append(k)
    else:
        h.append("*")
m=','.join(h)
j=m.maketrans({',':''})
print(m.translate(j))