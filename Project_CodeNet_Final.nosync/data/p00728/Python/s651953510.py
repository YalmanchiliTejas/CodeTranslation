import math
for i in range(30):
    n = int(input())
    if n == 0:
        break
    else:
        ls = []
        for i in range(n):
            ls.append(int(input()))
        ls.sort()
        ls.remove(ls[0])
        ls.remove(ls[-1])
        print(math.floor(sum(ls)/len(ls)))
