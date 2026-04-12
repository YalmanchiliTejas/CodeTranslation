import collections
def resolve():
    n = int(input())
    C = collections.Counter(list(input()))
    for i in range(n-1):
        S = collections.Counter(list(input()))
        C = C & S

    st = ''
    for i in sorted(C.items()):
        st += i[0] * i[1]
    print(st)

if __name__ == '__main__':
    resolve()