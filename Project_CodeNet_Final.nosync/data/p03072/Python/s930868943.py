n=int(input())
hlist=list(map(int,input().split()))
m=0
for i in range(n):
      if max(hlist[0:i+1])==hlist[i]:
            m+=1
print(m)


