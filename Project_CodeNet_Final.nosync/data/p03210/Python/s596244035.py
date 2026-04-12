import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    

X=input()

if X in "753":
	print("YES")
else:
	print("NO")