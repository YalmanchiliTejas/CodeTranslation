n=int(input())
s=[[] for i in range(n)]
for i in range(n):
    s[i]=list(input())
s1=list(set(s[0]))
s1.sort()
#print(s1)

stmin=[50]*len(s1)
for i in range(n):
    st=[0]*len(s1)
    for ii in range(len(s1)):
        for sij in s[i]:
            if s1[ii]==sij :
                st[ii]+=1
        stmin[ii]=min(stmin[ii],st[ii])

t=""
for i in range(len(s1)):
    for ii in range(stmin[i]):        
        t=t+s1[i]
print(t)