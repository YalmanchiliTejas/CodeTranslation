n=input()
n=int(n)

s=input()

k=input()
k=int(k)

tmp = s[k-1]
tmp_list=list(s)

for i in range(len(s)):
	if s[i]!=tmp:
		tmp_list[i]="*"

aaa = "".join(tmp_list)
print(aaa)
