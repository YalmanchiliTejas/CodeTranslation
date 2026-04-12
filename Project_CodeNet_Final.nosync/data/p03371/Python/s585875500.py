import sys
input = sys.stdin.readline
#input = sys.stdin.buffer.readline


def II(): return int(input())
def MI(): return map(int,input().split())
def LI(): return list(map(int,input().split()))

# mod=10**9+7
# rstrip().decode('utf-8')

def main():
	a,b,c,x,y=MI()
	ans=10**10
	ans=min(a*x+b*y,c*max(x,y)*2,c*min(x,y)*2+(a*(x-min(x,y)) if x>y else b*(y-min(x,y))))
	print(ans)











if __name__ == "__main__":
	main()
