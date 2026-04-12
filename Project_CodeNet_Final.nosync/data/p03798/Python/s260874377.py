n = int(input())
s = input()
ans = -1

for i in ['SS', 'SW', 'WW', 'WS']:
    narabi = ''
    narabi += i
    for k in range(n - 2):
        if narabi[-1] == 'S':
            if s[k + 1] == 'o':
                narabi += narabi[-2]
            else:
                if narabi[-2] == 'S':
                    narabi += 'W'
                else:
                    narabi += 'S'
        else:
            if s[k + 1] == 'o':
                if narabi[-2] == 'S':
                    narabi += 'W'
                else:
                    narabi += 'S'
            else:
                narabi += narabi[-2]
    kenshou = narabi[-2:]
    kenshou2 = kenshou + narabi[:2]
    kenshou_s = s[-1] + s[-0]
    for k in range(2):
        if kenshou[-1] == 'S':
            if kenshou_s[k] == 'o':
                kenshou += kenshou[-2]
            else:
                if kenshou[-2] == 'S':
                    kenshou += 'W'
                else:
                    kenshou += 'S'
        else:
            if kenshou_s[k] == 'o':
                if kenshou[-2] == 'S':
                    kenshou += 'W'
                else:
                    kenshou += 'S'
            else:
                kenshou += kenshou[-2]
    if kenshou == kenshou2:
        ans = narabi
        break
    # print(kenshou2)
    # print(kenshou)
    # print(narabi)
print(ans)
