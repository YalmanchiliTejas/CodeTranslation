S=str(input())
s_list = "aiueo"
n = len([1 for x in s_list if x==S])
if n==1:
  print("vowel")
else:
  print("consonant")