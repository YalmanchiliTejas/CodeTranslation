ps=[]
while True:
    p, s= map(int, input().split(","))
    if p==s==0: break
    ps.append((p, s))
o= sorted(set(s for p, s in ps), reverse=True)
zo= dict(zip(o, [i+1 for i in range(len(o))]))
while True:
    try:
        q= int(input())
        for p, s in ps:
            if p== q: print(zo[s])
    except:
        break