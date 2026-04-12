x = input().split()
print('yes' if all([x.count(x[i]) % 4 == 0 for i in range(len(x))]) else 'no')
