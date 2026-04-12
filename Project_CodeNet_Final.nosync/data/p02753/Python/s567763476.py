# print('input >>')
S = input()
dic = {}

for s in S:
    dic[s] = 1

# print('-----output-----')
if len(dic) == 2:
    print('Yes')
else:
    print('No')