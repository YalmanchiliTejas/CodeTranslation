s = input()
l = list(s)
ans= "No"
for i in range(0,len(l)-1):
  if(l[i]!= l[i+1]):
    ans = "Yes"
    break
print(ans)
  
