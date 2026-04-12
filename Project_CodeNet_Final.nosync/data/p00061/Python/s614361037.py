team=[0]*101
while 1:
    p,s=map(int,input().split(","))
    if p==s==0:break
    team[p]=s
rank=list(set(team))
rank.sort(reverse=True)
while 1:
    try:
        n=int(input())
        print(rank.index(team[n])+1)
    except:break
