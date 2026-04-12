A = {}
while True:
    p,s = map(int,input().split(','))
    if p == 0:
        break
    A [p] = s

while True:
    try:
        q = int(input())
    except EOFError:
        break
    st = {A [i] for i in A.keys() if i != q and A [i] > A [q]}
    print(len(st) + 1)