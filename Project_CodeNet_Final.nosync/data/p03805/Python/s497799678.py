import itertools as it

n,m=map(int,input().split())
ans=[]
for i in range(m):
    a,b=map(int,input().split())
    ans.append([a,b])
    ans.append([b,a])
  
a=0
for e in it.permutations(range(n)):
    #print(e)
    count=1
    if e[0]!=0:
        break
    
    for i in range(n-1):
        if [e[i]+1,e[i+1]+1] in ans:
            count*=1
        else:
            count*=0
            break
            
    a+=count
    
print(a)