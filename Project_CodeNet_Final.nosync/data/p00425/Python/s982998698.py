def North(ls):
    ls[1-1],ls[2-1],ls[5-1],ls[6-1] = ls[2-1],ls[6-1],ls[1-1],ls[5-1]
def East(ls):
    ls[1-1],ls[3-1],ls[4-1],ls[6-1] = ls[4-1],ls[1-1],ls[6-1],ls[3-1]
def West(ls):
    ls[1-1],ls[3-1],ls[4-1],ls[6-1] = ls[3-1],ls[6-1],ls[1-1],ls[4-1]
def South(ls):
    ls[1-1],ls[2-1],ls[5-1],ls[6-1] = ls[5-1],ls[1-1],ls[6-1],ls[2-1]
def Right(ls):
    ls[2-1],ls[3-1],ls[4-1],ls[5-1] = ls[3-1],ls[5-1],ls[2-1],ls[4-1]
def Left(ls):
    ls[2-1],ls[3-1],ls[4-1],ls[5-1] = ls[4-1],ls[2-1],ls[5-1],ls[3-1]

while True:
    try:
        n = int(raw_input())
        if n==0:
            break
        dice = [1,2,3,4,5,6] 
        # top, south, east, west, north, bottom
        direction = ""
        total = 1
        for k in range(n):
            direction = str(raw_input())
            if direction=="North":
                North(dice)
            elif direction=="East":
                East(dice)
            elif direction=="West":
                West(dice)
            elif direction=="South":
                South(dice)
            elif direction=="Right":
                Right(dice)
            elif direction=="Left":
                Left(dice)
            total += dice[0]
        print total
    except EOFError:
        break