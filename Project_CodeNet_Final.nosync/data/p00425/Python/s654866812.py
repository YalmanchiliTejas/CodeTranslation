rot = {
    "North": (1,5,2,3,0,4),
    "East" : (3,1,0,5,4,2),
    "West" : (2,1,5,0,4,3),
    "South": (4,0,2,3,5,1),
    "Right": (0,2,4,1,3,5),
    "Left" : (0,3,1,4,2,5)
}
while 1:
    n = int(raw_input())
    if not n:
        break
    dice = [1,2,3,4,5,6]
    ans = 0
    for i in xrange(n):
        r = rot[raw_input()]
        dice = [dice[r[i]] for i in xrange(6)]
        ans += dice[0]
    print ans+1