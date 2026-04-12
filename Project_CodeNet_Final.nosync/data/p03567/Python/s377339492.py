    
s = input()
ans = "No"
for i in range(len(s)-1):
  if s[i] == "A" and s[i+1] == "C":
    ans = "Yes"
    break
print(ans)
