n=int(input())
s=input()
k=s[int(input())-1]
a=''
for i in range(n):
  if s[i]==k:
    a+=k
  else:
    a+='*'
print(a)