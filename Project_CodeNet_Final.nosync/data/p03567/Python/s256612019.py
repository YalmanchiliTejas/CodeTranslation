S = input()
ans = "No"
for i in range(len(S)-1):
	if S[i:i+2] == "AC":
		ans = "Yes"

print(ans)