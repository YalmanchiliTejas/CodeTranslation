n= int(input())
l= input()
c=int(input())
c=l[c-1]
ans=""
for i in l:
   if i != c:
      ans+="*"
   else:
      ans+=c
print(ans)