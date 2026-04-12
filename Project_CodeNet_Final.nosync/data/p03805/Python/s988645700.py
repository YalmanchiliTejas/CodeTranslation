import itertools

n,m=map(int,input().split())

if n ==2:
    print(1)
    exit()

arr=[[_] for _ in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    #print(a,b)
    
    arr[a-1].append(b-1)
    arr[b-1].append(a-1)

#print("arr",arr)

route=list(itertools.permutations(range(1,n)))
#print("route",route) 
ans=0
for i in route:
    chk0=0
    chk=True
    if i[0] in arr[0]:
        chk0 =True
        #print(i)
        for j in range(1,n-1):
            if i[j] in arr[i[j-1]]:
                chk0+=1
                
                pass
            else:
                #print(1,i[j],arr[i[j-1]])
                break
                
    if chk0==n-1:
        
        ans+=1

print(ans)