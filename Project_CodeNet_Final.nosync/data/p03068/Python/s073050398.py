length= int(input())
moji = str(input())
num = int(input())
set = moji[num-1]
ans = ""
for i in range(length):
  if moji[i] != set:
    ans += "*"
  else:
    ans += moji[i]
print(ans)