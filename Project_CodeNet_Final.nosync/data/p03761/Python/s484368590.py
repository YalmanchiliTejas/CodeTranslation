from collections import Counter

n=int(input())
s=[input() for i in range(n)]

ss=Counter(s[0])

for i in range(1,n):
    check=Counter(s[i])
    
    for key,value in ss.items():
        ss[key]=min(value,check[key])
ans=[]
for key,value in ss.items():
    ans+=[key]*value
ans.sort()
print(''.join(ans))
