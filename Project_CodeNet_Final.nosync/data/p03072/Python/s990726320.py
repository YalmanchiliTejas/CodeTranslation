n=int(input())
h=list(int(x) for x in input().split())
cnt=1
for i  in range(1,n):
	if all(h[i]  >= h[j] for j in range(0,i)):
		cnt +=1
	else:
		continue
print(cnt)