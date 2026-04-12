nn,m=map(int,input().split())

C=[[] for i in range(nn)]
C.insert(0,"niku")

for i in range(m):
    a,b=map(int,input().split())
    C[a].append(b)
    C[b].append(a)

ans=0    

def tansa(n,path,app):
    new_path=path[:]
    new_path.append(app)
    #print(str(n)+"+",new_path,path)
    if len(new_path)==nn:
        global ans
        ans+=1
        return 1

    for num in C[n]:
        if not num in new_path:
            tansa(num,new_path,num)

            
tansa(1,[],1)

print(ans)