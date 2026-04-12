N,X=map(int,input().split())

hlist=[]
blist=[]
plist=[]
for i in range(N+1):
  hlist.append(2**(i+2)-3)
  #blist.append(2**(i+1)-2)
  plist.append(2**(i+1)-1)
  
#print(hlist)
#print(blist)
#print(plist)

num_p=0
while(True):
  #print(N,X,num_p)
  if N==0:
    num_p+=1
    break
  elif X==1:
    break
  elif X==hlist[N]//2+1:
    num_p+=plist[N-1]+1
    break
  elif X==hlist[N]:
    num_p+=plist[N]
    break
  elif X<hlist[N]//2+1:
    X-=1
    N-=1
  else:
    num_p+=plist[N-1]+1
    X-=hlist[N]//2+1
    N-=1
  
print(num_p)