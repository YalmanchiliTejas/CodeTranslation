n=int(input())
p=[[0]*n for i in range(26)]
for i in range(n):
    s=input()
    h=ord("a")
    for j in range(len(s)):
        p[ord(s[j])-h][i]+=1
c=""
for i in range(26):
    c+=min(p[i])*chr(h+i)
print(c)