N=int(input())
S=input()
K=int(input())
T=""
s=S[K-1]
for i in S:
    if i!=s:
        T+="*"
    else:
        T+=s
print(T)