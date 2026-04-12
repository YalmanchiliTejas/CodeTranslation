N= input()
ans = "No"
pre = ""
for i in N:
    if i != pre and pre != "":
        ans = "Yes"
    pre = i
print(ans)