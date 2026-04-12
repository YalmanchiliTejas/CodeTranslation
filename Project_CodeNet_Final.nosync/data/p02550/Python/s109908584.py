N, X, M = map(int, input().split())
NN = N
li = []
isused = [False] * M
while isused[X] == False and N != 0:
    li.append(X)
    isused[X] = True
    X = (X ** 2) % M
    N -= 1
    
if N == 0:
    print(sum(li))

elif N != 0 and X in li:
    l = len(li)
    s = li.index(X)
    T = l - s
    q = (NN - s) // T
    r = (NN - s) % T
    print(sum(li) + sum(li[i] for i in range(s, len(li))) * (q-1) + sum(li[i] for i in range(s, s + r)))