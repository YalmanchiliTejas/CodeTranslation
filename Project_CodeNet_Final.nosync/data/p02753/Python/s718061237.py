S = input()

ps = ''
for s in S:
    if s != ps and ps != '':
        print('Yes')
        break
    ps = s
else:
    print('No')