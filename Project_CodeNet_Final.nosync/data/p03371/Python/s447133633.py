import sys

#+++++
	



def main():
	a,b,c,x,y = map(int, input().split())
	
	get_price=lambda na,nb,nab:max(na,0) * a + max(nb,0) * b + max(nab,0) * c
	us=lambda x:max(0,x)
	
	r_min=get_price(x,y,0)
	#print(r_min)
	for i in range(max(x,y)+1):
		r=get_price(us(x - i), us(y - i), 2*i)
		r_min=r if r<r_min else r_min
		#print(r, '_',r_min)
	
	print(r_min)
	
	
#+++++

if __name__ == "__main__":
	if sys.platform =='ios':
		sys.stdin=open('inputFile.txt')
	else:
		input = sys.stdin.readline
		
	ret = main()
	if ret is not None:
		print(ret)
		
	if sys.platform =='ios':
		sys.stdin.close()