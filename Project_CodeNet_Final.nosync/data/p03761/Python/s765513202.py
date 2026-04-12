n=int(input())
s=[input() for i in range(n)]
l=[0]*26
moji=[]
for i in range(26):
  mini=len(s[0])
  for j in range(n):
    if s[j].count(chr(97+i))<mini:
      mini=s[j].count(chr(97+i))
  l[i]+=mini
for i in range(26):
  for j in range(l[i]):
    moji.append(chr(97+i))
print("".join(moji))