n=int(input())
l=[input() for i  in range(n)]
#print(l)
s={}
for i in range(len(l[0])):
    if l[0][i] in s.keys():
        s[l[0][i]]+=1
    else:
        s[l[0][i]]=1
#print(s)
for i in l:
    d={}
    for j in range(len(i)):
        if i[j] in d.keys():
            d[i[j]]+=1
        else:
            d[i[j]]=1
    for k in s.keys():
        for l in d.keys():
            if k==l:
                s[k]=min(s[k],d[l])
                break
        else:
            s[k]=0
s=sorted(s.items())
#print(s)
a=''
for i in s:
    if i[1]!=0:
        a+=i[0]*i[1]
print(a)