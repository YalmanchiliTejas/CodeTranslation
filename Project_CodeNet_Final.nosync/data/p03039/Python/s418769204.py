import sys
input = sys.stdin.buffer.readline

#sys.setrecursionlimit(10**9)
#from functools import lru_cache

def RD(): return input().rstrip().decode()
def II(): return int(input())
def FI(): return int(input())
def MI(): return map(int,input().split())
def MF(): return map(float,input().split())
def LI(): return list(map(int,input().split()))
def LF(): return list(map(float,input().split()))
def TI(): return tuple(map(int,input().split()))
# rstrip().decode()


def main():
	n,m,k=MI()
	mod=10**9+7

	ans=0

	cnt=0
	for i in range(1,m):
		cnt+=i*(m-i)
		cnt%=mod

	ans+=cnt*n*n
	ans%=mod

	cnt=0
	for i in range(1,n):
		cnt+=i*(n-i)
		cnt%=mod

	ans+=cnt*m*m
	ans%=mod

	f=[1]
	for i in range(1,n*m+5):
		f.append((f[-1]*i)%mod)

	finv=[]
	for i in f:
		finv.append(pow(i,mod-2,mod))
	#print(finv)

	#print(ans)

	ans*=k*(k-1)

	ans*=f[n*m-2]
	ans%=mod
	#print(ans)


	ans*=finv[n*m-2-(k-2)]
	ans%=mod
	#print(ans)


	ans*=finv[k]
	ans%=mod



	print(ans)






























if __name__ == "__main__":
	main()
