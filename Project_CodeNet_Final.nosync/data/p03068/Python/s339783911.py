n=int(input())
s=input()
k=int(input())
num = 0
for i in s:
  if i == s[k-1]:
    num +=1
  else:
    s = s.replace(s[num],'*')
    num +=1
print(s)