n = int(input())
s = input()

res = 'W'
if s[0] == 'o':
    res += 'S'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'W' and res[-2] == 'W':
        print(res[:-1])
        exit()
res = 'W'
if s[0] == 'o':
    res += 'W'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'W' and res[-2] == 'S':
        print(res[:-1])
        exit()
res = 'W'
if s[0] == 'x':
    res += 'S'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'W' and res[-2] == 'S':
        print(res[:-1])
        exit()
res = 'W'
if s[0] == 'x':
    res += 'W'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'W' and res[-2] == 'W':
        print(res[:-1])
        exit()

res = 'S'
if s[0] == 'o':
    res += 'S'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'S' and res[-2] == 'S':
        print(res[:-1])
        exit()
res = 'S'
if s[0] == 'o':
    res += 'W'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'S' and res[-2] == 'W':
        print(res[:-1])
        exit()
res = 'S'
if s[0] == 'x':
    res += 'S'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'S' and res[-2] == 'W':
        print(res[:-1])
        exit()
res = 'S'
if s[0] == 'x':
    res += 'W'
    for i in range(2,n+1):
        if s[i-1] == 'o':
            if res[i-1] == 'S':
                t = res[i-2]
            else:
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
        else:
            if res[i - 1] == 'S':
                if res[i-2] == 'S':
                    t = 'W'
                else:
                    t = 'S'
            else:
                t = res[i - 2]
        res += t
    if res[-1] == 'S' and res[-2] == 'S':
        print(res[:-1])
        exit()

print(-1)