input_colors = input().split(' ')
number = ''
for i in range(3):
    number += input_colors[i]
    
if int(number)%4 == 0:
    print('YES')
else:
    print('NO')