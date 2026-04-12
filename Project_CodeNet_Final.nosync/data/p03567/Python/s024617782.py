s = input()
ans = "No"
for i in range(0,len(s)-1):
    if s[i]+s[i+1] == "AC":
        ans = "Yes"
print(ans)
        
