f = True
while f:
    x = raw_input()
    x = int(x)
    l = []
    for i in range(x):
        l.append(int(raw_input()))
    if x == 0:
        f = False
    else:
        print (sum(l) - min(l) - max(l)) / (len(l) - 2)