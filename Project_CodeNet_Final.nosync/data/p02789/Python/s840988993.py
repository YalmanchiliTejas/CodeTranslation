ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

n,m = mi()

if n == m:
    print('Yes')
else:
    print('No')