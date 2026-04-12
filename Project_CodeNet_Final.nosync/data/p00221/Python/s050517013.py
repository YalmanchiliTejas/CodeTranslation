def iter( begin, end ):
    x = begin
    while x < end:
        yield x
        x += 1
    raise StopIteration

def valid( val , txt ):
    if val%15 == 0: return txt == 'FizzBuzz'
    if val%3 == 0: return txt == 'Fizz'
    if val%5 == 0: return txt == 'Buzz'
    return str(val) == txt
    
while True:
    m, n = map(int, raw_input().split())
    if m+n == 0: break
    player = [ x for x in iter(1, m+1) ]
    ind = 0
    for a in iter(1, n+1):
        txt = raw_input()
        if len(player) == 1: continue
        if valid( a, txt ):
            ind = (ind+1)%len(player)
        else:
            player.pop(ind)
            ind = ind%len(player)
    for p in player[:-1]:
        print p,
    print player[-1]
    