import itertools
N,M=map(int,input().split())
a=[]
b=[]
for i in range(M):
  a1,b1=map(int,input().split())
  a.append(a1)
  b.append(b1)

count=0

s=[i for i in range(1,N+1)]
x=list(itertools.permutations(s))
for i in x:
  if(i[0]!=1):
    break
  else:
    #print(i)
    flag=0
    for j in range(N-1):
      for k in range(len(a)):
        if((a[k]==i[j] and b[k]==i[j+1])or(b[k]==i[j] and a[k]==i[j+1])):
          flag+=1
          break
    if(flag==N-1):
      count+=1
print(count)