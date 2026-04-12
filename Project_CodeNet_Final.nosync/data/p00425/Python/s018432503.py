roll = {"North":("152304"), 
    "South":("402351"), 
    "East":("310542"), 
    "West":("215043"),
    "Right":("024135"),
    "Left":("031425")}
while True:
    n = int(input())
    if n == 0:
        break
    cnt = 1
    _dice = [i for i in range(1,7)]
    for i in range(n):
        _dice = [_dice[int(j)] for j in roll[input().strip()]]
        cnt+=_dice[0]
    print(cnt)
