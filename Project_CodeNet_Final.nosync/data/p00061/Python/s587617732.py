data = {}

while True:
    team, score = input().split(',')
    if team == score == '0': break
    if int(score) in data:
        data[int(score)].append(team)
    else:
        data[int(score)] = [team]

while True:
    try:
        n = input()
    except:
        break
    for d in data.keys():
        if n in data[d]:
            tmp = reversed(list(data.keys()))
            ind = list(tmp).index(d)
            print(ind + 1)