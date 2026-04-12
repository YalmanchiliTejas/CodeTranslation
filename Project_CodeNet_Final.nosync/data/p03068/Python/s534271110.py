N=int(input())
S=input()
l=len(S)
S=list(S)
K=int(input())#Kと異なる文字

B=[]
for i in range(N):
    if S[K-1]!=S[i]:
        B.append("*")
    elif S[K-1]==S[i]:
        B.append(S[i])

c="".join(B)
print(c)

