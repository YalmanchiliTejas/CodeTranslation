n=int(input())
S=list(map(str, [input() for i in range(n)]))
cont=[51]*26
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
ans=''
for i in range(n):
    for j in range(26):
        if cont[j]>S[i].count(alphabet[j]):
            cont[j]=S[i].count(alphabet[j])
for i in range(26):
    for j in range(cont[i]):
        ans=ans+alphabet[i]
print(ans)