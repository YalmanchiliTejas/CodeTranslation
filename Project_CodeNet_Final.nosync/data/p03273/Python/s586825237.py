a,b=map(int,input().split())
s=[]
dels=[]
for i in range(a):
    s.append(input())
for i in range(len(s)):
    f=1
    for j in range(b):
        if s[i][j]!='.':
            f=0
            break
    if f:
        dels.append(i)
k=0
for i in dels:
    del s[i-k]
    k=k+1
dels=[]
for i in range(b):
    f=1
    for j in range(len(s)):
        if s[j][i]!='.':
            f=0
            break
    if f:
        dels.append(i)



for i in dels:
    for j in range(len(s)):
        s[j]=s[j][:i]+' '+s[j][i+1:]

for i in s:
    for j in i:
        if j!=' ':
            print(j,end='')
    print()