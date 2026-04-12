import itertools as itl
n, m=map(int, input().split())
#ここでリストを作成する
hen=[]
check=0

for _ in range(m):
  hen.append(list(map(int, input().split())))
#print(hen)
l=list(range(2, n+1))
for v in itl.permutations(l):
  #print(v)
  for i in range(n-2):
    if not(sorted(v[i:i+2]) in hen) or not(list([1, v[0]]) in hen):
      break
  else:
    if n==2:
      check+=1
    elif i==n-3:
      check+=1
    continue
print(check)
  
  
      
    