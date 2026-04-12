import collections

n=int(input())
s=[]
ans=[[0 for _ in range(26)]for _ in range(n)]
#print(ans)
z=0
s=[input() for _ in range(n)]
for i in range(n):
    z=0
    for j in range(97,123):
        ans[i][z]=s[i].count(chr(j))
        z+=1
    #print(ans[i])
    
count=[]
count2=51
ans2=[0]*26
for i in range(26):
    count2=51
    for j in range(n):
        count2=min(count2,ans[j][i])
    ans2[i]=count2

for i in range(26):
    for j in range(ans2[i]):
        print(chr(i+97),end="")
