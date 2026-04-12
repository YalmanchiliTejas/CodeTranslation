n=int(input())
a=[int(input())*(-1) for _ in range(n)]
inf=10**10
l=[inf]*n
import bisect
for i in range(n):
	r=bisect.bisect_right(l,a[i])
	l[r]=a[i]
cnt=0
for i in range(n):
	if l[i]!=inf:
		cnt+=1
	else:
		break
print(cnt)