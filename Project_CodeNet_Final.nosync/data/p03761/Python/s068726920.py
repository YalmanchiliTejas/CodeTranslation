n=int(input())
a=[]
for i in range(n):
    s=list(str(input()))
    s.sort()
    a.append(s)
a.sort()

ans=''
for j in range(len(a[0])):
    for i in range(1,n):
        if a[0][j] not in a[i]:
            break
    else:
        ans+=a[0][j]
b=list(set(ans))
#print(b)
#print(a)
ANS=[]
for i in range(len(b)):
    c=[]
    for j in range(n):
        c.append(a[j].count(b[i]))
    ANS.append(min(c)*b[i])
ANS.sort()
ANS=''.join(map(str,ANS))
print(ANS)