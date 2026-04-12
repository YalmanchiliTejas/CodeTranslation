n=int(input())
s=[input() for i in range(n)]
cnt=[0]*26
t=[0]*26
for i,ss in enumerate(s):
  t=[0]*26
  if i==0:
    for sss in ss:
      cnt[ord(sss)-97]+=1
    continue
  for sss in ss:
    t[ord(sss)-97]+=1
  for i in range(26):
    if cnt[i]>t[i]:
      cnt[i]=t[i]
ans=""
for i in range(26):
  ans+=chr(i+97)*cnt[i]
print(ans)

