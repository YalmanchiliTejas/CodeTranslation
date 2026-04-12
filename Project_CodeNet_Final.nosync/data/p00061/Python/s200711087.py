ps, ses = [], []
while True:
    p, s = map(int, input().split(','))
    if not p:
        break
    ps.append(p)
    ses.append(s)
rank = []
for s in ses:
    if s not in rank:
        rank.append(s)
rank.sort(reverse=True)
while True:
    try:
        q = int(input())
    except:
        break
    print(rank.index(ses[ps.index(q)]) + 1)