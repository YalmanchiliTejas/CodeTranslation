txt = ""
num = (int)(input())
message = [[0 for i in range(26)] for j in range(num)]

for i in range(num):
  text = input()
  for j in text:
    #print(ord(j))
    message[i][ord(j) - 97] += 1
#print(message[0])
r_message = [[0 for i in range(num)] for j in range(26)]
for i in range(26):
  for j in range(num):
    r_message[i][j] = message[j][i]
#print(r_message)
for j in range(26):  
  for k in range(min(r_message[j])):
  	txt += chr(j + 97)
print(txt)