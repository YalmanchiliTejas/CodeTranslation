s = str(input())
list_s = list(s)
ans = "No"
for i in range(len(s)-1):
	if list_s[i] == "A" and list_s[i+1] == "C":
		ans = "Yes"
		break

print(ans)