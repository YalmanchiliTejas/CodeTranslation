import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
 


n,m=map(int,input().split())

if n==m:
	print("Yes")
else:
	print("No")
	