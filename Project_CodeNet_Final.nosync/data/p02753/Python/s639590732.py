cmin = lambda a,b : a if a<b else b
cmax = lambda a,b : a if a>b else b
iin = lambda : int(input())
lin = lambda : list(map(int,input().split()))
rin = lambda n : [int(input()) for _ in range(n)]

s = set(input())

print("No" if len(s)==1 else "Yes")
