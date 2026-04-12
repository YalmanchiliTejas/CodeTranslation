s = str(input())
ans = "No"
for i in range(2):
  if(s[i]!=s[i+1]):
    ans = "Yes"
print(ans)