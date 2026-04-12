from collections import Counter
from collections import OrderedDict

if __name__ == "__main__":
    n = int(input())
    s = list()
    for i in range(n):
        s.append(input())

    ans = Counter(s[0])

    for i in range(n):
        ans = ans & Counter(s[i])

    tmp = OrderedDict()
    tmp = sorted(ans)

    ansstr = ''

    for a in tmp:
        ansstr += a*ans[a]

    print(ansstr)
