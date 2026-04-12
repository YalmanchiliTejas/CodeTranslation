s = input()
m = s[0]
for i in range(2):
    if m !=  s[1+i]:
        print('Yes')
        break
else:
    print('No')