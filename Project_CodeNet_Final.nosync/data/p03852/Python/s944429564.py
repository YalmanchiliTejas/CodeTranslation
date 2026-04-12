import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    

S=input()

if S in "aeiou":
	print("vowel")
else:
	print("consonant")