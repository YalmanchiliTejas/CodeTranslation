l = ['q','w','e','r','t','a','s','d','f','g','z','x','c','v','b']

def which(c):
    return 0 if c in l else 1

while True:
    st = input()
    if st == "#": break
    lis = list(st)
    count = 0
    hand = which(lis[0])
    for c in lis:
        tmp = which(c)
        if tmp != hand:
            count += 1
        hand = tmp
    print(count)