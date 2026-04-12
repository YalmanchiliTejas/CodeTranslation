n = int(input())
s = list(str(input()))
k = int(input())
t = s[k-1]
for i in range(n):
  if s[i] == t:
    s[i] = s[i]
  else:
    s[i] = "*"
answer = ""
for i in range(n):
  answer = answer + s[i]
print(answer)