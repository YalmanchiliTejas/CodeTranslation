n=int(input())
s=input()
char_list=list(s)
k=int(input())
for i in range(n):
	if(char_list[k-1]!=char_list[i]):
  		char_list[i] = "*"
str = ''.join(char_list)
print(str)