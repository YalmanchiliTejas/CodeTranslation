teams = dict()
while 1:
    a, b = map(int, raw_input().split(','))
    if a == b == 0:
        break
    teams[a] = b
cur = 1 << 30
cur_rank = 0
ret = dict()
for k, v in sorted(teams.items(), key=lambda a: a[1], reverse=True):
    if v < cur:
        cur_rank += 1
        cur = v
    ret[k] = cur_rank

while 1:
    try:
        query = input()
        print ret[query]
    except EOFError:
        break