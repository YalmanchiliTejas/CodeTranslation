msg = 'YES' if int(''.join(list(map(str, input().split(' ')))))%4==0 else 'NO'
print(msg)