import sys

input_file = 'a1.in'
# sys.stdin = open(input_file)


s = input().split()
t = int(''.join(s))

if t % 4 == 0:
    print('YES')
else:
    print('NO')

