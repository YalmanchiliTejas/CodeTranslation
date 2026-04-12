n= input()
List = [97,101,105,111,117]
flag = 0
for i in range(5):
  if ord(n) == List[i]:
    flag =1
if flag == 1:
  print("vowel") 
else:
  print("consonant")
