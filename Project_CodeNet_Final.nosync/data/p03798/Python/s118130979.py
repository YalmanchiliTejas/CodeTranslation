from itertools import product

n = int(input())
s = input()

bl = False
for ef, el in product([1, -1], repeat=2):
    zoo = [0] * n
    zoo[0] = ef
    zoo[-1] = el
    for i, e in enumerate(s):
        if e == "o":
            if zoo[i] == 1:
                nxt = zoo[i-1]
            else:
                nxt = -zoo[i-1]

        else:
            if zoo[i] == 1:
                nxt = -zoo[i-1]
            else:
                nxt = zoo[i-1]

        if i < n - 2:
            zoo[i+1] = nxt

        elif nxt != zoo[(i+1)%n]:
            break

    else:
        bl = True
        break

if bl:
    ans = ["S" if e == 1 else "W" for e in zoo]
    print(*ans, sep="")

else:
    print(-1)
