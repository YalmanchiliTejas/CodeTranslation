n=int(input())
s=input()
k=int(input())
s_=str()
for i in range(n):
  if s[i]!=s[k-1]:
    s_+='*'
  else:
    s_+=s[i]
print(s_)