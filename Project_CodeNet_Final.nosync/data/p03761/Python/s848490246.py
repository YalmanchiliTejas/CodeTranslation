
def read_input():
    n = int(input())

    slist = []
    for i in range(n):
        slist.append(input().strip())

    return n, slist

def submit():
    n, slist = read_input()

    slist.sort(key=lambda x: len(x))

    slist = [[c for c in s] for s in slist]

    checker = [c for c in slist[0]]
    result = []
    for c in checker:
        for s in slist[1:]:
            if c not in s:
                break
        else:
            result.append(c)
            for s in slist[1:]:
                s.remove(c)

    result.sort()
    print(''.join(result))

if __name__ == '__main__':
    submit()