H, W = map(int,input().split())
A = [list(input()) for _ in range(H)]
first = 0
a = A[0]
a = list(reversed(a))
last = W - a.index('#') -1
if A[0][first:last+1] == ['#'] * len(A[0][first:last+1]):
    pass
else:
    print('Impossible')
    exit()

for i in range(1, H):
    a = A[i]
    if last == a.index('#'):
        first = last
    else:
        print('Impossible')
        exit()
    a = list(reversed(a))
    last = W - a.index('#') - 1
    if A[i][first:last+1] == ['#'] * len(A[i][first:last+1]):
        pass
    else:
        print('Impossible')
        exit()
print('Possible')
