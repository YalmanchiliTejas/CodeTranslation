n=int(input())
S=[]
T=[]
for i in range(n):
  S.append(input())
while True:
  char=S[0][0]
  min=len(S[0])
  for i in range(n):
    if S[i].count(char)<min:
      min=S[i].count(char)
    S[i]=S[i].replace(char,'')
  for i in range(min):
    T+=[char]
  if len(S[0])==0:
    break
T=sorted(T)
print(''.join(T))