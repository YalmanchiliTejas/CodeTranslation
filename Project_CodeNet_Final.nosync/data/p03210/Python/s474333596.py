#年齢が入力される
#7or5or3ならYES
#そうでないならNO

age = input()
age = int(age)

if age == 7 or age == 5 or age == 3:
    print('YES')
else:
    print('NO')
