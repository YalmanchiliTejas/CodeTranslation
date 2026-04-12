from sys import stdin

A, B, C = [int(x) for x in stdin.readline().rstrip().split()]

total = str(A) + str(B) + str(C)
if int(total) % 4 == 0:
    print('YES')
else:
    print('NO')