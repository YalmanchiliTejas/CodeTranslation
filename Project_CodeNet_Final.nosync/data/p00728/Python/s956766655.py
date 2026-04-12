trial = int(input())
while True:
    targ = []
    for t in range(trial):
        targ.append(int(input()))
    targ.remove(max(targ))
    targ.remove(min(targ))
    print(sum(targ) // len(targ))
    trial = int(input())
    if trial ==0:
        break