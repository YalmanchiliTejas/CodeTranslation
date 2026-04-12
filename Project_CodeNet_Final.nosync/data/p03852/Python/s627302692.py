s=input()
v=["a","i","u","e","o"]

vowel=False
for i in range(len(v)):
	if(v[i]==s):
		vowel=True
		break

if vowel==True:
	print("vowel")
else:
	print("consonant")

