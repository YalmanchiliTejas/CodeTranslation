S=input()
ans="No"
for i in range(5):
  if S[i:i+2]=="AC":
    ans="Yes"
    break
print(ans)    