N, M = map(int, raw_input().split() )
TimeStamp = 0
Stamp = "&Stamp&"
while N+M:
    not_found = {}
    Root = {}
    Root[Stamp] = TimeStamp
    TimeStamp+=1
    not_found[Stamp] = TimeStamp
    TimeStamp+=1
    Root["."] = Root
    Root[".."] = not_found 
    for i in range(N):
        url = raw_input()
        content = url.split('/');
        content.pop(0)
        cur = Root
        for x in content:
            if x not in cur:
                cur[x] = {}
                cur[x]['..'] = cur
                cur[x]['.'] = cur[x]
                cur[x][Stamp] = TimeStamp
                TimeStamp+=1
            cur = cur[x]
        cur['.is_file.'] = True
        if content[-1]=='index.html':
            cur['..']['/'] = cur
        cur['..'] = not_found
        cur['.'] = not_found
    for i in range(M):
        url1 = raw_input()
        content = url1.split('/')
        content.pop(0)
        res1 = Root
        for x in content:
            if x == '':
                x = '/'
            if x not in res1:
                res1 = not_found
                break;
            res1 = res1[x]
        if '/' in res1:
            res1 = res1['/']
        #
        url2 = raw_input()
        content = url2.split('/')
        content.pop(0)
        res2 = Root
        for x in content:
            if x == '':
                x = '/'
            if x not in res2:
                res2 = not_found
                break;
            res2 = res2[x]
        if '/' in res2:
            res2 = res2['/']

        if res1 == not_found or res2 == not_found:
            print "not found"
        elif '.is_file.' not in res1 or '.is_file.' not in res2:
            print "not found"
        elif res1[Stamp] == res2[Stamp]:
            print "yes"
        else:
            print "no"
    N, M = map(int, raw_input().split() )