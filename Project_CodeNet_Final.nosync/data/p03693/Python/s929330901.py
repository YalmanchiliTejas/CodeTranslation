i = input()
t = i.split()
num = int(t[0])*100 + int(t[1])*10 + int(t[2])
if num%4==0:
    print('YES')
else:
    print('NO')