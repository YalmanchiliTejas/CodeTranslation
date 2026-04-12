n = int(input())
list =list(input())
m = ""
j = int(input()) - 1
for i in range(n):
  if list[i] == list[j]:
    m += list[j]
  else:
    m += "*"
print(m)