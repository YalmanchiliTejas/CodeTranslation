flag = 1
data = []
query = []
while True:
    try:
        while flag:
            n,s = map(int, raw_input().split(","))
            if n == 0 and s == 0:
                flag = 0
                break
            data.append([s,n])
        query.append(int(raw_input()))
    except:
        break
    
data.sort(); data.reverse()

rank = 0
rslt = {}
mx = 31
for i in data:
    if i[0] < mx:
        rank += 1
        mx = i[0]
    rslt[i[1]] = rank

for i in query:
    print rslt[i]