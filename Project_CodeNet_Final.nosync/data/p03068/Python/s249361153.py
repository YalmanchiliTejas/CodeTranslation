n=int(input())
s=input()
k=int(input())

focus=s[k-1]
ans=""


for str_k in s:
  if str_k==focus:
    ans=ans+str_k
  else:
    ans=ans+"*"
print(ans)

