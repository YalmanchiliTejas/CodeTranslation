n = int(input())
s = input()
k = int(input())

ans_list = []
t = s[k-1]
for i in s:
  if i == t:
    ans_list.append(t)
  else:
    ans_list.append("*")
print("".join(ans_list))
  