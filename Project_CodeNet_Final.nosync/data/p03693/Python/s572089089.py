import sys
input=sys.stdin.readline

num = ''.join(list(input().split()))
if int(num)%4:
    print('NO')
else:
    print('YES')