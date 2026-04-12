Poi = []
Tea = []
while True:
    
    p,s = map(int,input().split(","))
    if p == 0 and s == 0:
        break
    Poi.append(s)
    Tea.append(p)
Poi_ran = sorted(sorted(set(Poi), key=Poi.index))
while True:
    try:
        q = int(input())
        point = Poi[Tea.index(q)]
        print(len(Poi_ran) - Poi_ran.index(point))
    except EOFError:
        break