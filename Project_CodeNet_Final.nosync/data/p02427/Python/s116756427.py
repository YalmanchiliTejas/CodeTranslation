n = int(input())
print('0:')
for x in range(1, 2**n):
    bits = [i for i, b in enumerate(f'{x:b}'[::-1]) if b == '1']
    print(f'{x}: {" ".join(map(str, bits))}')

