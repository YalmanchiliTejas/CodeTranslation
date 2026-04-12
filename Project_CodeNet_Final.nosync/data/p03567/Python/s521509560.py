n = input()

for i in range(len(n)-1):
    if n[i:i+2] == 'AC':
        print('Yes')
        break
else:
    print('No')
