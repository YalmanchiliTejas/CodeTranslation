from math import floor

while True:
    n = eval(input())
    if n != 0:
        ls = []
        for i in range(n):
            m = eval(input())
            ls.append(m)
        ls.remove(max(ls))
        ls.remove(min(ls))
        print(floor(sum(ls)/len(ls)))
    else:
        break