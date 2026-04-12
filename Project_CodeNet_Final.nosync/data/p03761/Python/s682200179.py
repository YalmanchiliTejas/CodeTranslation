N=int(input())
L=[[0 for i in range(N)]for j in range(26)]
A=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

for i in range(N):
    S=input()
    for j in range(len(S)):
        for k in range(26):
            if S[j]==A[k]:
                L[k][i]+=1
l=[100 for i in range(26)]

for a in range(26):
    for b in range(N):
        if L[a][b]<l[a]:
            l[a]=L[a][b]
#print(l)
ans=""
for c in range(26):
    ans+=A[c]*l[c]
print(ans)