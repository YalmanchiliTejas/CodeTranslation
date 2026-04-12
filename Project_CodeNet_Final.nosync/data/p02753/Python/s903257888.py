S=input()
ans="No"
for i in range(2):
    if S[i+1]!=S[i]:
        ans="Yes"
print(ans)
