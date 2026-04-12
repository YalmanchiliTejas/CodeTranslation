n=int(input())
s=[list(input()) for i in range(n)]
for i in range(n):
    s[i].sort()
word="abcdefghijklmnopqrstuvwxyz"
l=len(word)
data=[[0]*n for i in range(l)]
for i in range(n):
    k=0
    for j in range(l):
        while s[i][k]==word[j]:
            data[j][i]+=1
            k+=1
            if k==len(s[i]):
                break
        else:
            continue
        break
ans=""
for i in range(l):
    ans+=word[i]*min(data[i])
print(ans)