N = input()
Hs = list(map(int,input().split()))

mountains = [0]

can_see = 0

for H in Hs:
    mountains.append(H)
    if H == max(mountains):
        can_see += 1

print(can_see)
    