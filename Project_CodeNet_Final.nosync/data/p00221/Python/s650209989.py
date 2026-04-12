def fizzbuzz(i):
    if i % 15 == 0:
        return 'FizzBuzz'
    elif i % 5 == 0:
        return 'Buzz'
    elif i % 3 == 0:
        return 'Fizz'
    else:
        return str(i)

import sys
f = sys.stdin


while True:
    m, n = map(int, f.readline().split())
    if m == n == 0:
        break
    member = list(range(1, m + 1))
    s = [f.readline().strip() for _ in range(n)]

    pos = 0
    for i in range(n):
        if s[i] != fizzbuzz(i + 1):
            del member[pos]
            m = len(member)
            if m == 1:
                break
        else:
            pos += 1
        pos %= m
        
    print(*member)