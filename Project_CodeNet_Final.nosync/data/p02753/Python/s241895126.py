s = input()

prev = s[0]
for i in range(1, 3):
    if s[i] != prev:
        print('Yes')
        break
else:
    print('No')
