c = input().split()
a = ['NO', 'YES']
print(a[int(''.join(c[1:]))%4==0])