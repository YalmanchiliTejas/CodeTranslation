N=int(input())
alist=list(map(int,input().split()))
#print(alist)

answer=0
while max(alist)>=N:
  s=sum([a//N for a in alist])
  for i in range(N):
    dec=(alist[i]//N)*N    
    asc=s-(alist[i]//N)
    alist[i]-=dec-asc
  answer+=s
  
print(answer)