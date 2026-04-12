N = input()
while True:
    dic = {}
    for i in range(N):
        lis = raw_input().split()
        dic[lis[0]] = [3*int(lis[1])+int(lis[3]), N-i]
    
    for k, v in sorted(dic.items(), key=lambda x: (x[1][0], x[1][1]), reverse=True):
        print '%s,%s' % (k, v[0])

    N = input()
    if N == 0: break
    print