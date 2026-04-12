s = input()

sta = list(s)
b = True

for i in sta:
    if sta.count(i) == len(sta):
        b = False

if b:
    print('Yes')
else:
    print('No')