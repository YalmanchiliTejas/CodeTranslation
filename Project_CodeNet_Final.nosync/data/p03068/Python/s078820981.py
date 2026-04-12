N = int(input())
s = input()
index = int(input())

for i in range(N):
  if not s[i] == s[index - 1]:
    s = s[0:i] + '*' + s[i + 1:]
print(s)