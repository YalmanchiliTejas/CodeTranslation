s = str(input())
n = len(s)

ans = "No"
for i in range(1,n):
  if s[i-1] == "A" and s[i] == "C":
    ans = "Yes"
    break

print(ans)