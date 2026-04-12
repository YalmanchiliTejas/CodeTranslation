from collections import Counter
n=int(input())
s=[input() for i in range(n)]

dic1=Counter(s[0])

for i in range(1,n):
    dic2=Counter(s[i])
    
    for i,v in dic1.items():
        dic1[i]=min(v,dic2[i])
ans=[]
for i,v in dic1.items():
    ans+=[i]*v
ans.sort()
print(''.join(ans))
    
    