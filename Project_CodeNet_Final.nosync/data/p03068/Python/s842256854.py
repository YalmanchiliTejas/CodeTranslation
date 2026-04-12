N=int(input())
s=str(input())
K=int(input())
S=[]

for i in s:
    S.append(i)
k=S[K-1]
S=["*" if S[i]!=k else S[i] for i in range(N)]
print("".join(map(str,S)))
