import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
n=int(input())

print(800*n-n//15*200)