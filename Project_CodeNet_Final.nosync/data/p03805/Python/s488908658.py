import sys
input=sys.stdin.readline
n,m=map(int,input().split())
check=[[False]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    check[a-1][b-1]=True
    check[b-1][a-1]=True
l=[i for i in range(1,n)]
import itertools
count=0
for order in itertools.permutations(l,n-1):
    order=[0]+list(order)
    for i in range(n-1):
        if check[order[i]][order[i+1]]:
            pass
        else:
            break
    else:
        count+=1
print(count)
