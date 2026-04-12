N = int(input())
Hs = [int(a) for a in input().split()]

state = Hs[0]
score = 0
for h in Hs:
    if state == h:
        score += 1
    elif state < h:
        state = h
        score += 1
    else:
        pass

print(score)
