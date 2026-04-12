n = int(input())
s = input()
k = int(input())

a = s[k-1]
ans = []
for i in list(s):
  if i == a:
    ans.append(i)
  else:
    ans.append("*")
print("".join(ans))