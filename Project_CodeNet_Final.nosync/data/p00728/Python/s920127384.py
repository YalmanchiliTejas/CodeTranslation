while 1:
    n = input()
    if n == 0:
        break
    s = [input(), input()]
    if s[0] > s[1]:
        max = 0
        min = 1
    else:
        max = 1
        min = 0
    for i in range(2, n):
        s.append(input())
        if s[i] > s[max]:
            max = i
        elif s[i] < s[min]:
            min = i
    s[max] = 0
    s[min] = 0
    sum = 0
    for i in range(n):
        sum += s[i]
    ave = sum / (n-2)
    print ave