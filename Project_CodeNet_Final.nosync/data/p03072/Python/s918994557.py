a=int(input())
p=list(map(int,input().split()))
n=0

for i in range(a):
  if max(p[:i+1]) == p[i]:
    n += 1
    
print(n)