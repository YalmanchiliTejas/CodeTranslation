n = int(input())
s = input()
k = int(input())

sk = s[k-1]

new_s = ""
for cal in s:
  if cal != sk:
    new_s += "*"
  else:
    new_s += sk
print(new_s)