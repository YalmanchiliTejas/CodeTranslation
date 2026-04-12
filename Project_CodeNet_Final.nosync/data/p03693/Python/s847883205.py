cards=list(map(int,input().split()))
num=cards[0]*100+cards[1]*10+cards[2]
if num%4==0:
    print('YES')
else:
    print('NO')