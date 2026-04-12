n = int(input())
words = []
for i in range(n):
  word = str(input())
  word = "".join(sorted(word))
  words.append(word)

ans=""

for i in range(26):#chr(i+97)
  max_num = 50
  for word in words:
    num = word.count(chr(i+97))
    max_num = min(max_num,num)
  ans += chr(i+97) * max_num

print(ans)