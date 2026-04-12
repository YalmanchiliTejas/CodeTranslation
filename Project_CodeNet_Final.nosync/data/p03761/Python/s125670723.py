n=int(input())
x=[[0 for i in range(26)] for j in range(n)]
for i in range(n):
    s=input()
    for j in range(len(s)):
        x[i][ord(s[j])-97]+=1
ans=[0]*26
for i in range(26):
    ans[i]=min(x[j][i] for j in range(n))
a=[]
for i in range(26):
    for j in range(ans[i]):
        a.append(chr(97+i))
print("".join(a))

