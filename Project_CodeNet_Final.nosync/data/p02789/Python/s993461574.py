ii=lambda:int(input())
miis=lambda:map(int,input().split())
lmiis=lambda:list(map(int,input().split()))

n,m=miis()
print('Yes' if n==m else 'No')