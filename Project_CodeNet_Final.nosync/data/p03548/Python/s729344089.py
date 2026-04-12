import sys

if sys.platform =='ios':
    sys.stdin=open('input_file.txt')
    
x,y,z=map(int,input().split())

cnt=0

for i in range(1,x):
	if x>=y*i+z*(i+1):
		cnt+=1
	
	else:break
	

print(cnt)