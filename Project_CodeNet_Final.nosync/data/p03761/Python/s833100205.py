n = int(input())
if n==1:
    print(''.join(sorted(input())))
else:
    dic = {}
    s = input()
    for i in s:
        dic[i] = s.count(i)
    for i in range(n-1):
        s = input()
        for j in dic.keys():
            dic[j] = min(dic[j], s.count(j))
    s = ''
    for i in dic.keys():
        s += i*dic[i]
    print(''.join(sorted(s)))