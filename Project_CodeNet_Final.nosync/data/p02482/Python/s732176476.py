import sys
strict = raw_input()
str_list = strict.split(' ')
a = int(str_list[0])
b = int(str_list[1])

if( a > b ):
	print("a > b")
elif( a < b ):
	print("a < b")
else:
	print("a == b")