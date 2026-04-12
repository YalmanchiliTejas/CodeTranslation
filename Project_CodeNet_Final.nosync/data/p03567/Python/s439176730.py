import random
s=input()
ans="No"
for _ in range(1<<16):
  i=random.randrange(len(s)-1)
  if(s[i:i+2]=="AC"):
    ans="Yes"
print(ans)