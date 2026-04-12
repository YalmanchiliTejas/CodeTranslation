#正解数で順位を決定
team=[]
point=[]
dic={}
while True:
    p,s=map(int, input().split(","))
    if p==s==0:
        break
    team.append([p,s])
    if s not in point:
        point.append(s)
        
point.sort(reverse=True)

#辞書(得点,順位)で作る
for i in range(len(point)):
    dic[point[i]]=i+1
    
while True:
    try:
        n=int(input())
    except EOFError:
        break
    print(dic[team[n-1][1]])
    

