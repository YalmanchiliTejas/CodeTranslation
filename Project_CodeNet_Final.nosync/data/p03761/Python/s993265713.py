n=int(input())

#t={}
s=[]
#t=set(list(input()))
si=input()
lsi=list(si)
lsi.sort()
s.append([lsi[0],100])
for i in range(1,len(lsi)):
    if lsi[i]!=lsi[i-1]:
        s.append([lsi[i],100])
#print(s)
for j in range(len(s)):
    s[j][1]=min(s[j][1],si.count(s[j][0]))
for i in range(n-1):
    si=input()
    for j in range(len(s)):
        s[j][1]=min(s[j][1],si.count(s[j][0]))

#s=list(t)
strs=""
for i in range(len(s)):
    for ii in range(s[i][1]):
        strs=strs+s[i][0]
print(strs)
