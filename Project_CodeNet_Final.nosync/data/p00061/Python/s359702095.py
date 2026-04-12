lst = []

while True:
    p, s = map(int, input().split(','))

    if p == 0 :
        break

    lst.append(s)

s = list(set(lst))
s.sort(reverse = True)

while True:
    try:
        num = int(input())
        print(s.index(lst[num-1]) +1)

    except EOFError:
        break

