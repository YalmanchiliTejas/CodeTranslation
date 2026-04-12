n = int(input())
s = input()
#最初の二人だけ全探索
#x -> 狼
#o -> 羊
def check(li):
    for i in range(1,n-1):
        if li[i] == 'S':
            if li[i-1] == 'S':
                if s[i] == 'o':
                    li += ['S']
                else:
                    li += ['W']
            else:
                if s[i] == 'o':
                    li += ['W']
                else:
                    li += ['S']
        else:
            if li[i-1] == 'S':
                if s[i] == 'o':
                    li += ['W']
                else:
                    li += ['S']
            else:
                if s[i] == 'o':
                    li += ['S']
                else:
                    li += ['W']
    if li[-1] == 'S':
        if s[-1] == 'o':
            if li[-2] != li[0]:
                return False
        else:
            if li[-2] == li[0]:
                return False
    else:
        if s[-1] == 'o':
            if li[-2] == li[0]:
                return False
        else:
            if li[-2] != li[0]:
                return False

    if li[0] == 'S':
        if s[0] == 'o':
            if li[-1] != li[1]:
                return False
        else:
            if li[-1] == li[1]:
                return False
    else:
        if s[0] == 'o':
            if li[-1] == li[1]:
                return False
        else:
            if li[-1] != li[1]:
                return False
    return li
for i in range(2):
    for j in range(2):
        s1 = 'S' if i == 1 else 'W'
        s2 = 'S' if j == 1 else 'W'
        k = check([s1,s2])
        if k:
            print("".join(k))
            exit()
print(-1)