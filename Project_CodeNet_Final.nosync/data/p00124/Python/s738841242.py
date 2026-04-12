st=True
while True:
    n=int(input())
    if n==0:
        break
    if st==False:
        print()

    team={}
    for _ in range(n):
        data=input().split(" ")
        team[data[0]]=3*int(data[1])+int(data[3])
    team=team.items()
    team=sorted(team,key=lambda w:w[1],reverse=True)
    for t in team:
        print("{0},{1}".format(*t))
    st=False

