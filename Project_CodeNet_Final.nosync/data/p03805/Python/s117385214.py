import itertools
a,b=map(int,input().split())
A=[]
for _ in range(a-1):
  A.append(_+2)
List=[list(map(int,input().split())) for i in range(b)]
count=0
for i in itertools.permutations(A):
  ju=True
  if [1,i[0]] in List or [i[0],1] in List:
    ju=True
  else:
    ju=False
  for j in range(a-2):
    if not([i[j],i[j+1]] in List) and not([i[j+1],i[j]] in List):
      ju=False
  if ju:
    count+=1
print(count)