H,W=map(int,input().split())
G=[input()+"." for _ in range(H)]+["."*(W+1)]
G_cnt=sum([g.count("#") for g in G])
p=[0,0]
i=1
while(p!=[H-1,W-1]):
    if G[p[0]+1][p[1]]==G[p[0]][p[1]+1]:
        print("Impossible")
        break
    elif G[p[0]+1][p[1]]=="#":
        p=[p[0]+1,p[1]]
        i+=1
    else:
        p=[p[0],p[1]+1]
        i+=1
else:
    if i==G_cnt:
        print("Possible")
    else:
        print("Impossible")