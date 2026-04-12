_ = input()
s = input()

cands = ['SSS', 'SWW', 'WWS', 'WSW'] if s[0] == 'o' else ['WSS', 'SSW', 'SWS', 'WWW']

d = {
    'o':{'SS': 'S', 'SW': 'W', 'WW': 'S', 'WS': 'W'},
    'x':{'SS': 'W', 'SW': 'S', 'WW': 'W', 'WS': 'S'}
}

for char in s[1:]:
    for i in range(len(cands)):
        cands[i] += d[char][cands[i][-2:]]

for cand in cands:
    if cand[:2] == cand[-2:]:
        print(cand[1:-1])
        break
else:
    print(-1)