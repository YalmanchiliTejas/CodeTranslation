alpha = "abcdefghijklmnopqrstuvwxyz"
N = int(input())
L = []
for _ in range(N):
    L.append(input())
for char in alpha:
    minimum = 10 ** 10
    for string in L:
        cnt = 0
        for s in string:
            if s == char:
                cnt += 1
        minimum = min(cnt,minimum)
    print(char*minimum,end = '')
print()
