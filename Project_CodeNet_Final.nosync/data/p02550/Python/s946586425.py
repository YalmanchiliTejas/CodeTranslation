n, x, m = list(map(int, input().split()))

p = x
seen = {}
total = 0
done = False

for i in range(min(n, m)):
    total += p

    if p in seen:
        #print(p, "already seen!")
        cycleTotal = total - seen[p][1]
        cycleLength = i - seen[p][0]
        #print("total", cycleTotal, "length", cycleLength)

        iterationsLeft = (n-(i+1))
        total += (iterationsLeft//cycleLength) * cycleTotal

        iterationsLeft %= cycleLength

        for j in range(iterationsLeft):
            p = (p**2)%m
            total += p

        print(total)
        done = True
        break
    else:
        seen[p] = (i, total)

    p = (p**2)%m

if not done:
    print(total)