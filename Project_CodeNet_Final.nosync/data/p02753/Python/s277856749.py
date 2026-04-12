import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
a=input()

if a=="AAA" or a=="BBB":
  print("No")
else:
  print("Yes")
  
