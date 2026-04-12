n = int(input())
listNum = [int(x) for x in input().split()]
cnt = 1
big = listNum[0]
for i in range(1,n):
	if(big <= listNum[i]):
		big = listNum[i]
		cnt+=1
print(cnt)