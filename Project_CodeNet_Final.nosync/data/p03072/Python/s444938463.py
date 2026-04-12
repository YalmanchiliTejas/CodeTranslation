#coding:utf-8

N = int(input())
H = [int(x) for x in input().split()]

ans = 0

for i in range(N):
	if H[i] >= max(H[:(i+1)]):
		ans+=1
		
print(ans)