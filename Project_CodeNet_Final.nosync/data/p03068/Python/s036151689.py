n=int(input())
s=input()
k=int(input())
c=""
for i in range(n):
  if s[i]==s[k-1]:
    c+=s[i]
  else:
    c+="*"
print(c)