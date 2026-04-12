cmdic = {'North':0,'East':1,'West':3,'South':2,'Right':4,'Left':5}
roll = int(raw_input())
valis = []
while roll > 0:
    val = 1
    num = 1
    adj = [None,[2,4,5,3],[6,4,1,3],[2,1,5,6],[2,6,5,1],[1,4,6,3],[5,4,2,3]]
    for i in range(roll):
        cmd = cmdic[raw_input()]
        if cmd < 4:
            r1 = adj[num][(cmd+3)%4]
            r2 = adj[num][(cmd+1)%4]
            r3 = adj[num][(cmd+2)%4]
            if cmd == 1 or cmd == 3:
                adj[7-num] = adj[7-num][2:]+adj[7-num][:-2] 
                adj[r3] = adj[r3][2:]+adj[r3][:-2]
            num = adj[num][cmd]
            adj[r1] = adj[r1][-1:]+adj[r1][:-1]
            adj[r2] = adj[r2][1:]+adj[r2][:1]
        else:
            if cmd == 4:
                adj[num] = adj[num][-1:]+adj[num][:-1]
                for n in adj[num]:
                    adj[n] = adj[n][-1:]+adj[n][:-1]
                adj[7-num] = adj[7-num][1:]+adj[7-num][:1]
            if cmd == 5:
                adj[num] = adj[num][1:]+adj[num][:1]
                for n in adj[num]:
                    adj[n] = adj[n][1:]+adj[n][:1]
                adj[7-num] = adj[7-num][-1:]+adj[7-num][:-1]
        val += num
    valis.append(val)
    roll = int(raw_input())
for v in valis: print v