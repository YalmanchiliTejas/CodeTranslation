N, X, M = map(int, input().split())

mods = set()
modlist = []
a = X

mods.add(a % M)
modlist.append(a % M)

S = 0
while True:
    a = (a * a) % M

    if a == 0:
        print(sum(modlist))
        exit()

    if a in mods:
        S = modlist.index(a)
        break
    else:
        mods.add(a)
        modlist.append(a)

K = len(mods)
L = K - S
R = (N - S) % L
T = (N - S) // L

if N < K:
    print(sum(modlist[:N]))
    exit()

StartSum = sum(modlist[:S])
LoopSum = sum(modlist[S:K])
RemainSum = sum(modlist[S:][:R])

print(StartSum + LoopSum * T + RemainSum)