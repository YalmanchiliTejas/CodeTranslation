t = [0] * 101
while 1:
    p, s = map(int, input().split(','))
    if p == s == 0:
        break
    t[p] = s

rank = list(set(t))
rank.sort(reverse=True)

while 1:
    try:
        n = int(input())
        print(rank.index(t[n])+1)
    except:
        break

