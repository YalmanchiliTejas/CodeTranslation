n=int(input())
s=input()
k=int(input())
a=s[k-1]
ans=[]
for i in range(n):
  if s[i]==a:
    ans.append(a)
  else:
    ans.append('*')
print(''.join(ans))