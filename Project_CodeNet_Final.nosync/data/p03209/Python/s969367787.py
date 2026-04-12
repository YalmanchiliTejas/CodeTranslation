N, X = map(int, input().split())

burger = [1]
pati = [1]
for i in range(1,52):
    burger.append(burger[i-1]*2+3)
    pati.append(pati[i-1]*2+1)
    
def calc(l, eat):
    if l == 0:
        return 1
    elif eat == 1:
        return 0
    elif eat <= burger[l-1]+1:
        return calc(l-1, eat-1)
    elif eat == burger[l-1]+2:
        return pati[l-1] + 1
    elif eat <= (burger[l-1]+1)*2:
        return calc(l-1, eat-(2+burger[l-1])) + pati[l-1] + 1
    elif eat == (burger[l-1]*2) + 3:
        return (2*pati[l-1]) + 1

print(calc(N, X))