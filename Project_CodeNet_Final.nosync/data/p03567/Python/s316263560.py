S=list(raw_input())
#print S

ans="No"
for i in range(len(S)-1):
	#print S[i]+S[i+1]
	if S[i]+S[i+1]=="AC":
		ans="Yes"

print ans