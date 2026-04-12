S=input()
ans="No"
for i in range(len(S)):
    if "AC" == S[i:i+2]:
        ans="Yes"
        break
    
print(ans)

        

