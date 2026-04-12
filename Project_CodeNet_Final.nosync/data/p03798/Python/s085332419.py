n = int(input())
s = input()

w = {-1: 'W', 1: 'S'}
p = {1:'o', -1:'x'}
lst = [[1, 1], [-1, -1], [1, -1], [-1, 1]]

tmp = [0 for i in range(n+1)]
for a in lst:
    tmp[0] = a[0]
    tmp[1] = a[1]
    for i in range(1,n):
        tmp[i+1] = tmp[i-1] if s[i] == p[tmp[i]] else (tmp[i-1] * -1)
    if tmp[0] == tmp[-1]:
        flag = 1 if s[0] == p[tmp[0]] else -1
        if tmp[-2] == tmp[1] * flag:
            tmp.pop()
            print(''.join(map(w.get, tmp)))
            break
else:
    print(-1)
