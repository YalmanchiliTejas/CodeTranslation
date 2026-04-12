H,W = map(int,input().split())
a = []
[a.append(list(input())) for _ in range(H)]

while ["."]*W in a:
    a.remove(["."]*W)
    H -= 1

a_t = [list(x) for x in zip(*a)]

while ["."]*H in a_t:
    a_t.remove(["."]*H)

a = [list(x) for x in zip(*a_t)]
a_ = [''.join(x) for x in a]
[print(x) for x in a_]