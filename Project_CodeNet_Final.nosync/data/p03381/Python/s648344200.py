import copy
n=int(input())
a=list(map(int,input().split()))
b=a.copy()
a.sort()
for i in range(n):print(a[n//2 if a[n//2]>b[i]else n//2-1])