import sys

#+++++
		
def main():
	a = int(input())
	ret = 'YES' if ii(a) else 'NO'
	print(ret)
	
def ii(val):
	return val in [7,5,3]
	
	
#+++++
isTest=False

def pa(v):
	if isTest:
		print(v)

if __name__ == "__main__":
	if sys.platform =='ios':
		sys.stdin=open('inputFile.txt')
		isTest=True
	else:
		pass
		#input = sys.stdin.readline
			
	ret = main()
	if ret is not None:
		print(ret)