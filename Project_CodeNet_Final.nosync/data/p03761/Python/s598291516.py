alp=list('qawsedrftgyhujikoplmnbvcxz')
alp.sort()
# print(alp)
cnt=[]
for i in range(int(input())):
  tmp=[0 for _ in range(26)]
  for s in list(input()):
    tmp[alp.index(s)]+=1
  cnt.append(tmp)
  # print(tmp)
ans=''
for i in range(26):
  m=57
  for j in range(len(cnt)):
    m=min(m,cnt[j][i])
  ans+=alp[i]*m
print(ans)
