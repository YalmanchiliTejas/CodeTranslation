n = int(input())
s = input()
k = int(input())
li = []

for i in s:
  li.append(i)
check = li[k - 1]
for j in range(n):
  if li[j] != check:
    li[j] = "*"
ans = ""
for l in li:
  ans = ans + l
print(ans)