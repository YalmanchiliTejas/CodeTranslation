#B - *e**** ********e* *e****e* ****e**

len_of_s = int(input())
s = input()
k = int(input())

remain = s[k-1]
s_list = [i for i in s]

for i in range(len_of_s):
	if s_list[i] != remain:
		s_list[i] = "*"

result = "".join(s_list)
print(result) 