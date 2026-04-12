n=int(input())
s=[input() for i in range(n)]
dic={}
for i in range(n):
  for j in s[i]:
    if not(j in dic):
      dic[j]=[0 for i in range(n)]
    dic[j][i]+=1
ans=[]
for i in dic.keys():
  ans.append(i*min(dic[i]))
ans.sort()
print(*ans,sep='')