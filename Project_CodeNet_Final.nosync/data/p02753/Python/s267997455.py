S = list(input())
a = "".join(map(str,S[0:2]))
b = "".join(map(str,S[1:3]))
ans = "No"
if a == "AB" or a == "BA":
    ans = "Yes"
if b == "AB" or b == "BA":
    ans = "Yes"
print(ans)