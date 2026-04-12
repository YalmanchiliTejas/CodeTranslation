import bisect
cnt = 0
while 1:
    outs = []
    outn = []
    n = int(input())
    if n == 0: break
    elif cnt > 0: print()
    names = []
    scores = []
    for i in range(n):
        line = list(input().split())
        name = line[0]
        names.append(name)
        w = line[1]
        l = line[2]
        d = line[3]
        score = 3*int(w) + int(d)
        tm = bisect.bisect_left(outs, score)
        outs.insert(tm, score)
        outn.insert(tm, name)
        #scores.append(score)
    #ind = 1
    for i,j in zip(reversed(outn),reversed(outs)):
        print(f'{i},{j}')
        #if ind != n: print()
        #ind += 1
    #t = zip(scores, names)
    #t = sorted(t,reverse=True)
    #names,scores = zip(*t)
    #ind = 0
    #for i,j in t:
        #print(f'{j},{i}',end='')
        #if ind != len(t)-1: print()
        #ind += 1

    cnt += 1

