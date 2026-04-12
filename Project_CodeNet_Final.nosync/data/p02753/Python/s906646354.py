S = input()

cnt_A = 0
cnt_B = 0

for l in S:
    if l == 'A':
        cnt_A += 1
    else :
        cnt_B += 1

if cnt_A and cnt_B:
    print('Yes')
else :
    print('No')