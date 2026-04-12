N = input().split()
sn = ""
for i in N:
    sn += i
print('YES' if int(sn) % 4 == 0 else 'NO')