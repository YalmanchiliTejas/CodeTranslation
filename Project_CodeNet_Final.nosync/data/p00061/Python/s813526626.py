import sys
f = sys.stdin

teams = {}
scores = set()
while True:
    team, score = map(int, f.readline().split(','))
    if team == score == 0:
        break
    teams[team] = score
    scores.update([score])
scores = sorted(list(scores))[::-1]
for line in f:
    print(scores.index(teams[int(line)]) + 1)