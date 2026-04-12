n= int(input())
s=input()
k=int(input())
aa=-1
ans=[]
for i in s:
  if i ==s[k-1]:
    ans.append(i)
  else :
    ans.append('*')
anss=''.join(ans) 
print(''.join(ans) )