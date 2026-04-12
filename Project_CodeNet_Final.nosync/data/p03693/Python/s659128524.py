rgb = list(map(str,input().split()))
print('YES' if int(''.join(rgb)) % 4 == 0 else 'NO')