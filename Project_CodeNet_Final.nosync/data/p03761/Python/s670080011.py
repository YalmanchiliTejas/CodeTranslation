import collections
n=int(input())
S=[]

for i in range(n):
    s=list(str(input()))
    cc=collections.Counter(s)
    S.append(cc)
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

ans=[]
for lets in alphabet:
    nin=10**10
    for i in range(n):
        nin=min(nin,S[i][lets])
    for j in range(nin):
        ans.append(lets)
print("".join(ans))
