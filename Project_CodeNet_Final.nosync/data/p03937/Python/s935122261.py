h,w=map(int,input().split())
a=[]
for _ in range(h):
  a.append(input())
n=0
for ai in a:
  n+=ai.count('#')
print('Possible' if n==h+w-1 else 'Impossible')
