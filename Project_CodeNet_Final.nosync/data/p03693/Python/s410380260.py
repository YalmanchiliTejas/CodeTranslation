from functools import reduce
num = int(reduce(lambda a,b:a+b, input().split(), ""))
print('YES' if num%4 == 0 else 'NO')

