s=input()
s_len=len(s)
ans="No"
for i in range(s_len-1):
    if s[i:i+2]=="AC":
        ans="Yes"
        break
print(ans)